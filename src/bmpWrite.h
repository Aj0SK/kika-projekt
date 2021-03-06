#ifndef BMPWRITE_H
#define BMPWRITE_H

#include <iostream>
#include <vector>
#include <fstream>

namespace bmp
{
    using bytes = std::vector<std::byte>;

    void killNicely(const std::string& errMsg)
    {
        std::cerr << errMsg << std::endl;
        exit(1);
    }

    template<typename T>
    bytes splitIntToBytes(T x)
    {
        const int32_t typeSize = sizeof(x);
        bytes out;
    
        for(int32_t i=0; i<typeSize; ++i)
        {
            std::byte currByte = static_cast<std::byte>(x & 0xFF);
            out.push_back(currByte);
            x >>= 8;
        }
    
        //reverse(out.begin(), out.end());
    
        return out;
    }

    void bmpWrite(const std::string& destFile,
        const int32_t W,
        const int32_t H,
        const bytes& data
    )
    {
        std::ofstream fout(destFile, std::ios::out | std::ios::binary);

        if (fout.fail())
        {
            killNicely("Can't open file for writing");
        }
    
        const uint32_t bytesPerColor = 3;
        const uint32_t headSize = 14;
        const uint32_t infoHeadSize = 40;
        const uint32_t totalSize = bytesPerColor * W * H * sizeof(std::byte) + headSize + infoHeadSize;
    
        bytes signatureB = {static_cast<std::byte>('B'), static_cast<std::byte>('M')};
        bytes fileSizeB = splitIntToBytes<uint32_t> (totalSize);
        bytes reservedB = splitIntToBytes<uint32_t> (0);
        bytes DataOffsetB = splitIntToBytes<uint32_t>(headSize + infoHeadSize);
    
        bytes SizeB = splitIntToBytes<uint32_t>(infoHeadSize);
        bytes WidthB = splitIntToBytes<uint32_t>(W);
        bytes HeightB = splitIntToBytes<uint32_t>(H);
        bytes PlanesB = splitIntToBytes<uint16_t>(1);
        bytes BitsPerPixelB = splitIntToBytes<uint16_t>(8*bytesPerColor);
        bytes CompressionB = splitIntToBytes<uint32_t>(0);
        bytes ImageSizeB = splitIntToBytes<uint32_t>(0);
        bytes XpixelsPerM = splitIntToBytes<uint32_t>(1000);
        bytes YpixelsPerM = splitIntToBytes<uint32_t>(1000);
        bytes ColorsUsed = splitIntToBytes<uint32_t>(65536);
        bytes ImportantColors = splitIntToBytes<uint32_t>(0);
    
        bytes out;
    
        out.insert(out.end(), signatureB.begin(), signatureB.end());
        out.insert(out.end(), fileSizeB.begin(), fileSizeB.end());
        out.insert(out.end(), reservedB.begin(), reservedB.end());
        out.insert(out.end(), DataOffsetB.begin(), DataOffsetB.end());
    
        out.insert(out.end(), SizeB.begin(), SizeB.end());
        out.insert(out.end(), WidthB.begin(), WidthB.end());
        out.insert(out.end(), HeightB.begin(), HeightB.end());
        out.insert(out.end(), PlanesB.begin(), PlanesB.end());
        out.insert(out.end(), BitsPerPixelB.begin(), BitsPerPixelB.end());
        out.insert(out.end(), CompressionB.begin(), CompressionB.end());
        out.insert(out.end(), ImageSizeB.begin(), ImageSizeB.end());
        out.insert(out.end(), XpixelsPerM.begin(), XpixelsPerM.end());
        out.insert(out.end(), YpixelsPerM.begin(), YpixelsPerM.end());
        out.insert(out.end(), ColorsUsed.begin(), ColorsUsed.end());
        out.insert(out.end(), ImportantColors.begin(), ImportantColors.end());
    
        for(int32_t i=0; i<H; ++i)
        {
            uint32_t beg = (H-1-i)*W*bytesPerColor;
            out.insert(out.end(), data.begin() + beg, data.begin() + beg + W*bytesPerColor);
        }
    
        if (out.size() != totalSize)
        {
            killNicely("Bad size of buffer.");
        }
    
        fout.write((char *)out.data(), sizeof(std::byte)*out.size());
        fout.close();
    }
}

#endif

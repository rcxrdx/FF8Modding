#pragma once

#include <windows.h>
#include <memory>
#include <array>
#include <stdint.h>

#pragma pack(1)
#pragma pack(push)
struct ddv_class
{
    HANDLE mFileHandle;
    DWORD ddvVersion;
    DWORD contains;
    DWORD frameRate;
    DWORD mNumberOfFrames;
    DWORD field5;
    DWORD width;
    DWORD height;
    DWORD maxVideoFrameSize;
    DWORD field9;
    DWORD keyFrameRate;
    DWORD audioFormat;
    DWORD sampleRate;
    DWORD maxAudioFrameSize;
    DWORD mSingleAudioFrameSize;
    DWORD framesInterleave;
    WORD* mRawFrameBitStreamData;
    WORD* mDecodedBitStream;
    WORD* mAudioFrameBuffer;
    WORD* mDecodedSoundBuffer;
    DWORD mAudioFrameSizeBytesQ;
    DWORD mAudioFrameSizeBitsQ;
    DWORD nNumMacroblocksX;
    DWORD nNumMacroblocksY;
    BYTE mHasAudio;
    BYTE mHasVideo;
    BYTE field_62;      // Padding?
    BYTE field_63;      // Padding?
    DWORD mAudioFrameNumber;
    DWORD mAudioFrameNumberQ;
    DWORD field_6C; // Some sort of counter
    DWORD mVideoFrameSizesArray;        // After the audio/number of interleave frames
    DWORD mCurrentVideoFrameSizePtr;
    DWORD field_78;
    DWORD field_7C;
    DWORD mCurrentFrameBuffer;
    DWORD field_84;
    DWORD mSizeOfWhatIsReadIntoMUnknownBuffer2;
    WORD* mMacroBlockBuffer_q;
    DWORD mBlockDataSize_q;
};
#pragma pack(pop)


void InstallHooks();

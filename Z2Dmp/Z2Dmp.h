/*++

Copyright (c) 2017 - 2018, Comae Technologies DMCC

--*/


#pragma once

#include "stdafx.h"


#ifndef COMAE_TOOLKIT_VERSION
#define COMAE_TOOLKIT_VERSION "3.0.0.undefined"
#endif

#define ZDMP_FILE_SIGNATURE 'PMDZ'
#define ZDMP_BLOCK_SIGNATURE 'KLBZ'

#define ZDMP_FILE_VERSION_10 0x0100

#define PAGE_SIZE 4096


typedef struct _ZDMP_FILE_HEADER {
    ULONG Signature; // ZDMP_FILE_SIGNATURE
    ULONG Version; // ZDMP_FILE_VERSION
    LARGE_INTEGER FileSize;
    ULONG BlockSize;
    USHORT DataType; // Encryption or Compression
    USHORT CompressionFormat;
} ZDMP_FILE_HEADER, *PZDMP_FILE_HEADER;

typedef struct _ZDMP_BLOCK_HEADER {
    ULONG Signature;
    ULONG DataSize;
    ULONG Crc32;
} ZDMP_BLOCK_HEADER, *PZDMP_BLOCK_HEADER;


typedef
NTSTATUS
(NTAPI *PRTL_DECOMPRESS_BUFFER)(
    _In_ USHORT CompressionFormat,
    _Out_ PUCHAR UncompressedBuffer,
    _In_ ULONG UncompressedBufferSize,
    _In_ PUCHAR CompressedBuffer,
    _In_ ULONG CompressedBufferSize,
    _Out_ PULONG FinalUncompressedSize
    );


PRTL_DECOMPRESS_BUFFER RtlDecompressBuffer;

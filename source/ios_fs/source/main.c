#include <stdint.h>
#include <stdio.h>
#include <assert.h>

typedef struct __attribute__((packed)) {
    uint32_t initialized;
    uint64_t titleId;
    uint32_t processId;
    uint32_t groupId;
    uint32_t unk0;
    uint64_t capabilityMask;
    uint8_t unk1[0x4518];
    char unk2[0x280];
    char unk3[0x280];
    void* mutex;
} FSAProcessData;
static_assert(sizeof(FSAProcessData) == 0x4A3C, "FSAProcessData: wrong size");

typedef struct __attribute__((packed)) {
    uint32_t opened;
    FSAProcessData* processData;
    char unk0[0x10];
    char unk1[0x90];
    uint32_t unk2;
    char work_dir[0x280];
    uint32_t unk3;
} FSAClientHandle;
static_assert(sizeof(FSAClientHandle) == 0x330, "FSAClientHandle: wrong size");

int FSA_ioctl0x28_hook(FSAClientHandle* handle)
{
    printf("Updating client capabilities for handle %p\n", handle);
    handle->processData->capabilityMask = 0xffffffffffffffff;
    return 0;
}

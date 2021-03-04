/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#ifndef QAPI_TYPES_H
#define QAPI_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include "qapi/qmp/qobject.h"

#ifndef QAPI_TYPES_BUILTIN
#define QAPI_TYPES_BUILTIN


typedef struct anyList anyList;

struct anyList {
    union {
        QObject *value;
        uint64_t padding;
    };
    anyList *next;
};

void qapi_free_anyList(anyList *obj);

typedef struct boolList boolList;

struct boolList {
    union {
        bool value;
        uint64_t padding;
    };
    boolList *next;
};

void qapi_free_boolList(boolList *obj);

typedef struct int16List int16List;

struct int16List {
    union {
        int16_t value;
        uint64_t padding;
    };
    int16List *next;
};

void qapi_free_int16List(int16List *obj);

typedef struct int32List int32List;

struct int32List {
    union {
        int32_t value;
        uint64_t padding;
    };
    int32List *next;
};

void qapi_free_int32List(int32List *obj);

typedef struct int64List int64List;

struct int64List {
    union {
        int64_t value;
        uint64_t padding;
    };
    int64List *next;
};

void qapi_free_int64List(int64List *obj);

typedef struct int8List int8List;

struct int8List {
    union {
        int8_t value;
        uint64_t padding;
    };
    int8List *next;
};

void qapi_free_int8List(int8List *obj);

typedef struct intList intList;

struct intList {
    union {
        int64_t value;
        uint64_t padding;
    };
    intList *next;
};

void qapi_free_intList(intList *obj);

typedef struct numberList numberList;

struct numberList {
    union {
        double value;
        uint64_t padding;
    };
    numberList *next;
};

void qapi_free_numberList(numberList *obj);

typedef struct sizeList sizeList;

struct sizeList {
    union {
        uint64_t value;
        uint64_t padding;
    };
    sizeList *next;
};

void qapi_free_sizeList(sizeList *obj);

typedef struct strList strList;

struct strList {
    union {
        char *value;
        uint64_t padding;
    };
    strList *next;
};

void qapi_free_strList(strList *obj);

typedef struct uint16List uint16List;

struct uint16List {
    union {
        uint16_t value;
        uint64_t padding;
    };
    uint16List *next;
};

void qapi_free_uint16List(uint16List *obj);

typedef struct uint32List uint32List;

struct uint32List {
    union {
        uint32_t value;
        uint64_t padding;
    };
    uint32List *next;
};

void qapi_free_uint32List(uint32List *obj);

typedef struct uint64List uint64List;

struct uint64List {
    union {
        uint64_t value;
        uint64_t padding;
    };
    uint64List *next;
};

void qapi_free_uint64List(uint64List *obj);

typedef struct uint8List uint8List;

struct uint8List {
    union {
        uint8_t value;
        uint64_t padding;
    };
    uint8List *next;
};

void qapi_free_uint8List(uint8List *obj);

#endif /* QAPI_TYPES_BUILTIN */


typedef struct ACPIOSTInfo ACPIOSTInfo;

typedef struct ACPIOSTInfoList ACPIOSTInfoList;

typedef enum ACPISlotType {
    ACPI_SLOT_TYPE_DIMM = 0,
    ACPI_SLOT_TYPE_MAX = 1,
} ACPISlotType;

extern const char *const ACPISlotType_lookup[];

typedef struct Abort Abort;

typedef struct AcpiTableOptions AcpiTableOptions;

typedef enum ActionCompletionMode {
    ACTION_COMPLETION_MODE_INDIVIDUAL = 0,
    ACTION_COMPLETION_MODE_GROUPED = 1,
    ACTION_COMPLETION_MODE_MAX = 2,
} ActionCompletionMode;

extern const char *const ActionCompletionMode_lookup[];

typedef struct AddfdInfo AddfdInfo;

typedef struct BalloonInfo BalloonInfo;

typedef enum BiosAtaTranslation {
    BIOS_ATA_TRANSLATION_AUTO = 0,
    BIOS_ATA_TRANSLATION_NONE = 1,
    BIOS_ATA_TRANSLATION_LBA = 2,
    BIOS_ATA_TRANSLATION_LARGE = 3,
    BIOS_ATA_TRANSLATION_RECHS = 4,
    BIOS_ATA_TRANSLATION_MAX = 5,
} BiosAtaTranslation;

extern const char *const BiosAtaTranslation_lookup[];

typedef enum BlkdebugEvent {
    BLKDEBUG_EVENT_L1_UPDATE = 0,
    BLKDEBUG_EVENT_L1_GROW_ALLOC_TABLE = 1,
    BLKDEBUG_EVENT_L1_GROW_WRITE_TABLE = 2,
    BLKDEBUG_EVENT_L1_GROW_ACTIVATE_TABLE = 3,
    BLKDEBUG_EVENT_L2_LOAD = 4,
    BLKDEBUG_EVENT_L2_UPDATE = 5,
    BLKDEBUG_EVENT_L2_UPDATE_COMPRESSED = 6,
    BLKDEBUG_EVENT_L2_ALLOC_COW_READ = 7,
    BLKDEBUG_EVENT_L2_ALLOC_WRITE = 8,
    BLKDEBUG_EVENT_READ_AIO = 9,
    BLKDEBUG_EVENT_READ_BACKING_AIO = 10,
    BLKDEBUG_EVENT_READ_COMPRESSED = 11,
    BLKDEBUG_EVENT_WRITE_AIO = 12,
    BLKDEBUG_EVENT_WRITE_COMPRESSED = 13,
    BLKDEBUG_EVENT_VMSTATE_LOAD = 14,
    BLKDEBUG_EVENT_VMSTATE_SAVE = 15,
    BLKDEBUG_EVENT_COW_READ = 16,
    BLKDEBUG_EVENT_COW_WRITE = 17,
    BLKDEBUG_EVENT_REFTABLE_LOAD = 18,
    BLKDEBUG_EVENT_REFTABLE_GROW = 19,
    BLKDEBUG_EVENT_REFTABLE_UPDATE = 20,
    BLKDEBUG_EVENT_REFBLOCK_LOAD = 21,
    BLKDEBUG_EVENT_REFBLOCK_UPDATE = 22,
    BLKDEBUG_EVENT_REFBLOCK_UPDATE_PART = 23,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC = 24,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC_HOOKUP = 25,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC_WRITE = 26,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC_WRITE_BLOCKS = 27,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC_WRITE_TABLE = 28,
    BLKDEBUG_EVENT_REFBLOCK_ALLOC_SWITCH_TABLE = 29,
    BLKDEBUG_EVENT_CLUSTER_ALLOC = 30,
    BLKDEBUG_EVENT_CLUSTER_ALLOC_BYTES = 31,
    BLKDEBUG_EVENT_CLUSTER_FREE = 32,
    BLKDEBUG_EVENT_FLUSH_TO_OS = 33,
    BLKDEBUG_EVENT_FLUSH_TO_DISK = 34,
    BLKDEBUG_EVENT_PWRITEV_RMW_HEAD = 35,
    BLKDEBUG_EVENT_PWRITEV_RMW_AFTER_HEAD = 36,
    BLKDEBUG_EVENT_PWRITEV_RMW_TAIL = 37,
    BLKDEBUG_EVENT_PWRITEV_RMW_AFTER_TAIL = 38,
    BLKDEBUG_EVENT_PWRITEV = 39,
    BLKDEBUG_EVENT_PWRITEV_ZERO = 40,
    BLKDEBUG_EVENT_PWRITEV_DONE = 41,
    BLKDEBUG_EVENT_EMPTY_IMAGE_PREPARE = 42,
    BLKDEBUG_EVENT_MAX = 43,
} BlkdebugEvent;

extern const char *const BlkdebugEvent_lookup[];

typedef struct BlkdebugInjectErrorOptions BlkdebugInjectErrorOptions;

typedef struct BlkdebugInjectErrorOptionsList BlkdebugInjectErrorOptionsList;

typedef struct BlkdebugSetStateOptions BlkdebugSetStateOptions;

typedef struct BlkdebugSetStateOptionsList BlkdebugSetStateOptionsList;

typedef struct BlockDeviceInfo BlockDeviceInfo;

typedef struct BlockDeviceInfoList BlockDeviceInfoList;

typedef enum BlockDeviceIoStatus {
    BLOCK_DEVICE_IO_STATUS_OK = 0,
    BLOCK_DEVICE_IO_STATUS_FAILED = 1,
    BLOCK_DEVICE_IO_STATUS_NOSPACE = 2,
    BLOCK_DEVICE_IO_STATUS_MAX = 3,
} BlockDeviceIoStatus;

extern const char *const BlockDeviceIoStatus_lookup[];

typedef struct BlockDeviceMapEntry BlockDeviceMapEntry;

typedef struct BlockDeviceStats BlockDeviceStats;

typedef struct BlockDeviceTimedStats BlockDeviceTimedStats;

typedef struct BlockDeviceTimedStatsList BlockDeviceTimedStatsList;

typedef struct BlockDirtyBitmap BlockDirtyBitmap;

typedef struct BlockDirtyBitmapAdd BlockDirtyBitmapAdd;

typedef struct BlockDirtyInfo BlockDirtyInfo;

typedef struct BlockDirtyInfoList BlockDirtyInfoList;

typedef enum BlockErrorAction {
    BLOCK_ERROR_ACTION_IGNORE = 0,
    BLOCK_ERROR_ACTION_REPORT = 1,
    BLOCK_ERROR_ACTION_STOP = 2,
    BLOCK_ERROR_ACTION_MAX = 3,
} BlockErrorAction;

extern const char *const BlockErrorAction_lookup[];

typedef struct BlockInfo BlockInfo;

typedef struct BlockInfoList BlockInfoList;

typedef struct BlockJobInfo BlockJobInfo;

typedef struct BlockJobInfoList BlockJobInfoList;

typedef enum BlockJobType {
    BLOCK_JOB_TYPE_COMMIT = 0,
    BLOCK_JOB_TYPE_STREAM = 1,
    BLOCK_JOB_TYPE_MIRROR = 2,
    BLOCK_JOB_TYPE_BACKUP = 3,
    BLOCK_JOB_TYPE_MAX = 4,
} BlockJobType;

extern const char *const BlockJobType_lookup[];

typedef struct BlockStats BlockStats;

typedef struct BlockStatsList BlockStatsList;

typedef enum BlockdevAioOptions {
    BLOCKDEV_AIO_OPTIONS_THREADS = 0,
    BLOCKDEV_AIO_OPTIONS_NATIVE = 1,
    BLOCKDEV_AIO_OPTIONS_MAX = 2,
} BlockdevAioOptions;

extern const char *const BlockdevAioOptions_lookup[];

typedef struct BlockdevBackup BlockdevBackup;

typedef struct BlockdevCacheInfo BlockdevCacheInfo;

typedef struct BlockdevCacheOptions BlockdevCacheOptions;

typedef enum BlockdevChangeReadOnlyMode {
    BLOCKDEV_CHANGE_READ_ONLY_MODE_RETAIN = 0,
    BLOCKDEV_CHANGE_READ_ONLY_MODE_READ_ONLY = 1,
    BLOCKDEV_CHANGE_READ_ONLY_MODE_READ_WRITE = 2,
    BLOCKDEV_CHANGE_READ_ONLY_MODE_MAX = 3,
} BlockdevChangeReadOnlyMode;

extern const char *const BlockdevChangeReadOnlyMode_lookup[];

typedef enum BlockdevDetectZeroesOptions {
    BLOCKDEV_DETECT_ZEROES_OPTIONS_OFF = 0,
    BLOCKDEV_DETECT_ZEROES_OPTIONS_ON = 1,
    BLOCKDEV_DETECT_ZEROES_OPTIONS_UNMAP = 2,
    BLOCKDEV_DETECT_ZEROES_OPTIONS_MAX = 3,
} BlockdevDetectZeroesOptions;

extern const char *const BlockdevDetectZeroesOptions_lookup[];

typedef enum BlockdevDiscardOptions {
    BLOCKDEV_DISCARD_OPTIONS_IGNORE = 0,
    BLOCKDEV_DISCARD_OPTIONS_UNMAP = 1,
    BLOCKDEV_DISCARD_OPTIONS_MAX = 2,
} BlockdevDiscardOptions;

extern const char *const BlockdevDiscardOptions_lookup[];

typedef enum BlockdevDriver {
    BLOCKDEV_DRIVER_ARCHIPELAGO = 0,
    BLOCKDEV_DRIVER_BLKDEBUG = 1,
    BLOCKDEV_DRIVER_BLKVERIFY = 2,
    BLOCKDEV_DRIVER_BOCHS = 3,
    BLOCKDEV_DRIVER_CLOOP = 4,
    BLOCKDEV_DRIVER_DMG = 5,
    BLOCKDEV_DRIVER_FILE = 6,
    BLOCKDEV_DRIVER_FTP = 7,
    BLOCKDEV_DRIVER_FTPS = 8,
    BLOCKDEV_DRIVER_HOST_CDROM = 9,
    BLOCKDEV_DRIVER_HOST_DEVICE = 10,
    BLOCKDEV_DRIVER_HTTP = 11,
    BLOCKDEV_DRIVER_HTTPS = 12,
    BLOCKDEV_DRIVER_NULL_AIO = 13,
    BLOCKDEV_DRIVER_NULL_CO = 14,
    BLOCKDEV_DRIVER_PARALLELS = 15,
    BLOCKDEV_DRIVER_QCOW = 16,
    BLOCKDEV_DRIVER_QCOW2 = 17,
    BLOCKDEV_DRIVER_QED = 18,
    BLOCKDEV_DRIVER_QUORUM = 19,
    BLOCKDEV_DRIVER_RAW = 20,
    BLOCKDEV_DRIVER_TFTP = 21,
    BLOCKDEV_DRIVER_VDI = 22,
    BLOCKDEV_DRIVER_VHDX = 23,
    BLOCKDEV_DRIVER_VMDK = 24,
    BLOCKDEV_DRIVER_VPC = 25,
    BLOCKDEV_DRIVER_VVFAT = 26,
    BLOCKDEV_DRIVER_MAX = 27,
} BlockdevDriver;

extern const char *const BlockdevDriver_lookup[];

typedef enum BlockdevOnError {
    BLOCKDEV_ON_ERROR_REPORT = 0,
    BLOCKDEV_ON_ERROR_IGNORE = 1,
    BLOCKDEV_ON_ERROR_ENOSPC = 2,
    BLOCKDEV_ON_ERROR_STOP = 3,
    BLOCKDEV_ON_ERROR_MAX = 4,
} BlockdevOnError;

extern const char *const BlockdevOnError_lookup[];

typedef struct BlockdevOptions BlockdevOptions;

typedef struct BlockdevOptionsArchipelago BlockdevOptionsArchipelago;

typedef struct BlockdevOptionsBase BlockdevOptionsBase;

typedef struct BlockdevOptionsBlkdebug BlockdevOptionsBlkdebug;

typedef struct BlockdevOptionsBlkverify BlockdevOptionsBlkverify;

typedef struct BlockdevOptionsFile BlockdevOptionsFile;

typedef struct BlockdevOptionsGenericCOWFormat BlockdevOptionsGenericCOWFormat;

typedef struct BlockdevOptionsGenericFormat BlockdevOptionsGenericFormat;

typedef struct BlockdevOptionsNull BlockdevOptionsNull;

typedef struct BlockdevOptionsQcow2 BlockdevOptionsQcow2;

typedef struct BlockdevOptionsQuorum BlockdevOptionsQuorum;

typedef struct BlockdevOptionsVVFAT BlockdevOptionsVVFAT;

typedef struct BlockdevRef BlockdevRef;

typedef enum BlockdevRefKind {
    BLOCKDEV_REF_KIND_DEFINITION = 0,
    BLOCKDEV_REF_KIND_REFERENCE = 1,
    BLOCKDEV_REF_KIND_MAX = 2,
} BlockdevRefKind;

extern const char *const BlockdevRefKind_lookup[];

typedef struct BlockdevRefList BlockdevRefList;

typedef struct BlockdevSnapshot BlockdevSnapshot;

typedef struct BlockdevSnapshotInternal BlockdevSnapshotInternal;

typedef struct BlockdevSnapshotSync BlockdevSnapshotSync;

typedef struct ChardevBackend ChardevBackend;

typedef struct ChardevBackendInfo ChardevBackendInfo;

typedef struct ChardevBackendInfoList ChardevBackendInfoList;

typedef enum ChardevBackendKind {
    CHARDEV_BACKEND_KIND_FILE = 0,
    CHARDEV_BACKEND_KIND_SERIAL = 1,
    CHARDEV_BACKEND_KIND_PARALLEL = 2,
    CHARDEV_BACKEND_KIND_PIPE = 3,
    CHARDEV_BACKEND_KIND_SOCKET = 4,
    CHARDEV_BACKEND_KIND_UDP = 5,
    CHARDEV_BACKEND_KIND_PTY = 6,
    CHARDEV_BACKEND_KIND_NULL = 7,
    CHARDEV_BACKEND_KIND_MUX = 8,
    CHARDEV_BACKEND_KIND_MSMOUSE = 9,
    CHARDEV_BACKEND_KIND_BRAILLE = 10,
    CHARDEV_BACKEND_KIND_TESTDEV = 11,
    CHARDEV_BACKEND_KIND_STDIO = 12,
    CHARDEV_BACKEND_KIND_CONSOLE = 13,
    CHARDEV_BACKEND_KIND_SPICEVMC = 14,
    CHARDEV_BACKEND_KIND_SPICEPORT = 15,
    CHARDEV_BACKEND_KIND_VC = 16,
    CHARDEV_BACKEND_KIND_RINGBUF = 17,
    CHARDEV_BACKEND_KIND_MEMORY = 18,
    CHARDEV_BACKEND_KIND_MAX = 19,
} ChardevBackendKind;

extern const char *const ChardevBackendKind_lookup[];

typedef struct ChardevDummy ChardevDummy;

typedef struct ChardevFile ChardevFile;

typedef struct ChardevHostdev ChardevHostdev;

typedef struct ChardevInfo ChardevInfo;

typedef struct ChardevInfoList ChardevInfoList;

typedef struct ChardevMux ChardevMux;

typedef struct ChardevReturn ChardevReturn;

typedef struct ChardevRingbuf ChardevRingbuf;

typedef struct ChardevSocket ChardevSocket;

typedef struct ChardevSpiceChannel ChardevSpiceChannel;

typedef struct ChardevSpicePort ChardevSpicePort;

typedef struct ChardevStdio ChardevStdio;

typedef struct ChardevUdp ChardevUdp;

typedef struct ChardevVC ChardevVC;

typedef struct CommandInfo CommandInfo;

typedef struct CommandInfoList CommandInfoList;

typedef struct CommandLineOptionInfo CommandLineOptionInfo;

typedef struct CommandLineOptionInfoList CommandLineOptionInfoList;

typedef struct CommandLineParameterInfo CommandLineParameterInfo;

typedef struct CommandLineParameterInfoList CommandLineParameterInfoList;

typedef enum CommandLineParameterType {
    COMMAND_LINE_PARAMETER_TYPE_STRING = 0,
    COMMAND_LINE_PARAMETER_TYPE_BOOLEAN = 1,
    COMMAND_LINE_PARAMETER_TYPE_NUMBER = 2,
    COMMAND_LINE_PARAMETER_TYPE_SIZE = 3,
    COMMAND_LINE_PARAMETER_TYPE_MAX = 4,
} CommandLineParameterType;

extern const char *const CommandLineParameterType_lookup[];

typedef struct CpuDefinitionInfo CpuDefinitionInfo;

typedef struct CpuDefinitionInfoList CpuDefinitionInfoList;

typedef struct CpuInfo CpuInfo;

typedef struct CpuInfoList CpuInfoList;

typedef enum DataFormat {
    DATA_FORMAT_UTF8 = 0,
    DATA_FORMAT_BASE64 = 1,
    DATA_FORMAT_MAX = 2,
} DataFormat;

extern const char *const DataFormat_lookup[];

typedef struct DevicePropertyInfo DevicePropertyInfo;

typedef struct DevicePropertyInfoList DevicePropertyInfoList;

typedef enum DirtyBitmapStatus {
    DIRTY_BITMAP_STATUS_ACTIVE = 0,
    DIRTY_BITMAP_STATUS_DISABLED = 1,
    DIRTY_BITMAP_STATUS_FROZEN = 2,
    DIRTY_BITMAP_STATUS_MAX = 3,
} DirtyBitmapStatus;

extern const char *const DirtyBitmapStatus_lookup[];

typedef struct DriveBackup DriveBackup;

typedef struct DummyForceArrays DummyForceArrays;

typedef struct DumpGuestMemoryCapability DumpGuestMemoryCapability;

typedef enum DumpGuestMemoryFormat {
    DUMP_GUEST_MEMORY_FORMAT_ELF = 0,
    DUMP_GUEST_MEMORY_FORMAT_KDUMP_ZLIB = 1,
    DUMP_GUEST_MEMORY_FORMAT_KDUMP_LZO = 2,
    DUMP_GUEST_MEMORY_FORMAT_KDUMP_SNAPPY = 3,
    DUMP_GUEST_MEMORY_FORMAT_MAX = 4,
} DumpGuestMemoryFormat;

extern const char *const DumpGuestMemoryFormat_lookup[];

typedef struct DumpGuestMemoryFormatList DumpGuestMemoryFormatList;

typedef enum ErrorClass {
    ERROR_CLASS_GENERIC_ERROR = 0,
    ERROR_CLASS_COMMAND_NOT_FOUND = 1,
    ERROR_CLASS_DEVICE_ENCRYPTED = 2,
    ERROR_CLASS_DEVICE_NOT_ACTIVE = 3,
    ERROR_CLASS_DEVICE_NOT_FOUND = 4,
    ERROR_CLASS_KVM_MISSING_CAP = 5,
    ERROR_CLASS_MAX = 6,
} ErrorClass;

extern const char *const ErrorClass_lookup[];

typedef struct EventInfo EventInfo;

typedef struct EventInfoList EventInfoList;

typedef struct FdsetFdInfo FdsetFdInfo;

typedef struct FdsetFdInfoList FdsetFdInfoList;

typedef struct FdsetInfo FdsetInfo;

typedef struct FdsetInfoList FdsetInfoList;

typedef enum GuestPanicAction {
    GUEST_PANIC_ACTION_PAUSE = 0,
    GUEST_PANIC_ACTION_MAX = 1,
} GuestPanicAction;

extern const char *const GuestPanicAction_lookup[];

typedef enum HostMemPolicy {
    HOST_MEM_POLICY_DEFAULT = 0,
    HOST_MEM_POLICY_PREFERRED = 1,
    HOST_MEM_POLICY_BIND = 2,
    HOST_MEM_POLICY_INTERLEAVE = 3,
    HOST_MEM_POLICY_MAX = 4,
} HostMemPolicy;

extern const char *const HostMemPolicy_lookup[];

typedef struct IOThreadInfo IOThreadInfo;

typedef struct IOThreadInfoList IOThreadInfoList;

typedef struct ImageCheck ImageCheck;

typedef struct ImageInfo ImageInfo;

typedef struct ImageInfoList ImageInfoList;

typedef struct ImageInfoSpecific ImageInfoSpecific;

typedef enum ImageInfoSpecificKind {
    IMAGE_INFO_SPECIFIC_KIND_QCOW2 = 0,
    IMAGE_INFO_SPECIFIC_KIND_VMDK = 1,
    IMAGE_INFO_SPECIFIC_KIND_MAX = 2,
} ImageInfoSpecificKind;

extern const char *const ImageInfoSpecificKind_lookup[];

typedef struct ImageInfoSpecificQCow2 ImageInfoSpecificQCow2;

typedef struct ImageInfoSpecificVmdk ImageInfoSpecificVmdk;

typedef struct InetSocketAddress InetSocketAddress;

typedef enum InputAxis {
    INPUT_AXIS_X = 0,
    INPUT_AXIS_Y = 1,
    INPUT_AXIS_MAX = 2,
} InputAxis;

extern const char *const InputAxis_lookup[];

typedef struct InputBtnEvent InputBtnEvent;

typedef enum InputButton {
    INPUT_BUTTON_LEFT = 0,
    INPUT_BUTTON_MIDDLE = 1,
    INPUT_BUTTON_RIGHT = 2,
    INPUT_BUTTON_WHEEL_UP = 3,
    INPUT_BUTTON_WHEEL_DOWN = 4,
    INPUT_BUTTON_MAX = 5,
} InputButton;

extern const char *const InputButton_lookup[];

typedef struct InputEvent InputEvent;

typedef enum InputEventKind {
    INPUT_EVENT_KIND_KEY = 0,
    INPUT_EVENT_KIND_BTN = 1,
    INPUT_EVENT_KIND_REL = 2,
    INPUT_EVENT_KIND_ABS = 3,
    INPUT_EVENT_KIND_MAX = 4,
} InputEventKind;

extern const char *const InputEventKind_lookup[];

typedef struct InputEventList InputEventList;

typedef struct InputKeyEvent InputKeyEvent;

typedef struct InputMoveEvent InputMoveEvent;

typedef enum IoOperationType {
    IO_OPERATION_TYPE_READ = 0,
    IO_OPERATION_TYPE_WRITE = 1,
    IO_OPERATION_TYPE_MAX = 2,
} IoOperationType;

extern const char *const IoOperationType_lookup[];

typedef enum JSONType {
    JSON_TYPE_STRING = 0,
    JSON_TYPE_NUMBER = 1,
    JSON_TYPE_INT = 2,
    JSON_TYPE_BOOLEAN = 3,
    JSON_TYPE_NULL = 4,
    JSON_TYPE_OBJECT = 5,
    JSON_TYPE_ARRAY = 6,
    JSON_TYPE_VALUE = 7,
    JSON_TYPE_MAX = 8,
} JSONType;

extern const char *const JSONType_lookup[];

typedef struct KeyValue KeyValue;

typedef enum KeyValueKind {
    KEY_VALUE_KIND_NUMBER = 0,
    KEY_VALUE_KIND_QCODE = 1,
    KEY_VALUE_KIND_MAX = 2,
} KeyValueKind;

extern const char *const KeyValueKind_lookup[];

typedef struct KeyValueList KeyValueList;

typedef struct KvmInfo KvmInfo;

typedef enum LostTickPolicy {
    LOST_TICK_POLICY_DISCARD = 0,
    LOST_TICK_POLICY_DELAY = 1,
    LOST_TICK_POLICY_MERGE = 2,
    LOST_TICK_POLICY_SLEW = 3,
    LOST_TICK_POLICY_MAX = 4,
} LostTickPolicy;

extern const char *const LostTickPolicy_lookup[];

typedef struct MachineInfo MachineInfo;

typedef struct MachineInfoList MachineInfoList;

typedef struct Memdev Memdev;

typedef struct MemdevList MemdevList;

typedef struct MemoryDeviceInfo MemoryDeviceInfo;

typedef enum MemoryDeviceInfoKind {
    MEMORY_DEVICE_INFO_KIND_DIMM = 0,
    MEMORY_DEVICE_INFO_KIND_MAX = 1,
} MemoryDeviceInfoKind;

extern const char *const MemoryDeviceInfoKind_lookup[];

typedef struct MemoryDeviceInfoList MemoryDeviceInfoList;

typedef enum MigrationCapability {
    MIGRATION_CAPABILITY_XBZRLE = 0,
    MIGRATION_CAPABILITY_RDMA_PIN_ALL = 1,
    MIGRATION_CAPABILITY_AUTO_CONVERGE = 2,
    MIGRATION_CAPABILITY_ZERO_BLOCKS = 3,
    MIGRATION_CAPABILITY_COMPRESS = 4,
    MIGRATION_CAPABILITY_EVENTS = 5,
    MIGRATION_CAPABILITY_X_POSTCOPY_RAM = 6,
    MIGRATION_CAPABILITY_MAX = 7,
} MigrationCapability;

extern const char *const MigrationCapability_lookup[];

typedef struct MigrationCapabilityStatus MigrationCapabilityStatus;

typedef struct MigrationCapabilityStatusList MigrationCapabilityStatusList;

typedef struct MigrationInfo MigrationInfo;

typedef enum MigrationParameter {
    MIGRATION_PARAMETER_COMPRESS_LEVEL = 0,
    MIGRATION_PARAMETER_COMPRESS_THREADS = 1,
    MIGRATION_PARAMETER_DECOMPRESS_THREADS = 2,
    MIGRATION_PARAMETER_X_CPU_THROTTLE_INITIAL = 3,
    MIGRATION_PARAMETER_X_CPU_THROTTLE_INCREMENT = 4,
    MIGRATION_PARAMETER_MAX = 5,
} MigrationParameter;

extern const char *const MigrationParameter_lookup[];

typedef struct MigrationParameters MigrationParameters;

typedef struct MigrationStats MigrationStats;

typedef enum MigrationStatus {
    MIGRATION_STATUS_NONE = 0,
    MIGRATION_STATUS_SETUP = 1,
    MIGRATION_STATUS_CANCELLING = 2,
    MIGRATION_STATUS_CANCELLED = 3,
    MIGRATION_STATUS_ACTIVE = 4,
    MIGRATION_STATUS_POSTCOPY_ACTIVE = 5,
    MIGRATION_STATUS_COMPLETED = 6,
    MIGRATION_STATUS_FAILED = 7,
    MIGRATION_STATUS_MAX = 8,
} MigrationStatus;

extern const char *const MigrationStatus_lookup[];

typedef enum MirrorSyncMode {
    MIRROR_SYNC_MODE_TOP = 0,
    MIRROR_SYNC_MODE_FULL = 1,
    MIRROR_SYNC_MODE_NONE = 2,
    MIRROR_SYNC_MODE_INCREMENTAL = 3,
    MIRROR_SYNC_MODE_MAX = 4,
} MirrorSyncMode;

extern const char *const MirrorSyncMode_lookup[];

typedef struct MouseInfo MouseInfo;

typedef struct MouseInfoList MouseInfoList;

typedef struct NameInfo NameInfo;

typedef struct NetClientOptions NetClientOptions;

typedef enum NetClientOptionsKind {
    NET_CLIENT_OPTIONS_KIND_NONE = 0,
    NET_CLIENT_OPTIONS_KIND_NIC = 1,
    NET_CLIENT_OPTIONS_KIND_USER = 2,
    NET_CLIENT_OPTIONS_KIND_TAP = 3,
    NET_CLIENT_OPTIONS_KIND_L2TPV3 = 4,
    NET_CLIENT_OPTIONS_KIND_SOCKET = 5,
    NET_CLIENT_OPTIONS_KIND_VDE = 6,
    NET_CLIENT_OPTIONS_KIND_DUMP = 7,
    NET_CLIENT_OPTIONS_KIND_BRIDGE = 8,
    NET_CLIENT_OPTIONS_KIND_HUBPORT = 9,
    NET_CLIENT_OPTIONS_KIND_NETMAP = 10,
    NET_CLIENT_OPTIONS_KIND_VHOST_USER = 11,
    NET_CLIENT_OPTIONS_KIND_MAX = 12,
} NetClientOptionsKind;

extern const char *const NetClientOptionsKind_lookup[];

typedef enum NetFilterDirection {
    NET_FILTER_DIRECTION_ALL = 0,
    NET_FILTER_DIRECTION_RX = 1,
    NET_FILTER_DIRECTION_TX = 2,
    NET_FILTER_DIRECTION_MAX = 3,
} NetFilterDirection;

extern const char *const NetFilterDirection_lookup[];

typedef struct NetLegacy NetLegacy;

typedef struct NetLegacyNicOptions NetLegacyNicOptions;

typedef struct Netdev Netdev;

typedef struct NetdevBridgeOptions NetdevBridgeOptions;

typedef struct NetdevDumpOptions NetdevDumpOptions;

typedef struct NetdevHubPortOptions NetdevHubPortOptions;

typedef struct NetdevL2TPv3Options NetdevL2TPv3Options;

typedef struct NetdevNetmapOptions NetdevNetmapOptions;

typedef struct NetdevNoneOptions NetdevNoneOptions;

typedef struct NetdevSocketOptions NetdevSocketOptions;

typedef struct NetdevTapOptions NetdevTapOptions;

typedef struct NetdevUserOptions NetdevUserOptions;

typedef struct NetdevVdeOptions NetdevVdeOptions;

typedef struct NetdevVhostUserOptions NetdevVhostUserOptions;

typedef enum NetworkAddressFamily {
    NETWORK_ADDRESS_FAMILY_IPV4 = 0,
    NETWORK_ADDRESS_FAMILY_IPV6 = 1,
    NETWORK_ADDRESS_FAMILY_UNIX = 2,
    NETWORK_ADDRESS_FAMILY_UNKNOWN = 3,
    NETWORK_ADDRESS_FAMILY_MAX = 4,
} NetworkAddressFamily;

extern const char *const NetworkAddressFamily_lookup[];

typedef enum NewImageMode {
    NEW_IMAGE_MODE_EXISTING = 0,
    NEW_IMAGE_MODE_ABSOLUTE_PATHS = 1,
    NEW_IMAGE_MODE_MAX = 2,
} NewImageMode;

extern const char *const NewImageMode_lookup[];

typedef struct NumaNodeOptions NumaNodeOptions;

typedef struct NumaOptions NumaOptions;

typedef enum NumaOptionsKind {
    NUMA_OPTIONS_KIND_NODE = 0,
    NUMA_OPTIONS_KIND_MAX = 1,
} NumaOptionsKind;

extern const char *const NumaOptionsKind_lookup[];

typedef struct ObjectPropertyInfo ObjectPropertyInfo;

typedef struct ObjectPropertyInfoList ObjectPropertyInfoList;

typedef struct ObjectTypeInfo ObjectTypeInfo;

typedef struct ObjectTypeInfoList ObjectTypeInfoList;

typedef enum OnOffAuto {
    ON_OFF_AUTO_AUTO = 0,
    ON_OFF_AUTO_ON = 1,
    ON_OFF_AUTO_OFF = 2,
    ON_OFF_AUTO_MAX = 3,
} OnOffAuto;

extern const char *const OnOffAuto_lookup[];

typedef struct PCDIMMDeviceInfo PCDIMMDeviceInfo;

typedef struct PciBridgeInfo PciBridgeInfo;

typedef struct PciBusInfo PciBusInfo;

typedef struct PciDeviceClass PciDeviceClass;

typedef struct PciDeviceId PciDeviceId;

typedef struct PciDeviceInfo PciDeviceInfo;

typedef struct PciDeviceInfoList PciDeviceInfoList;

typedef struct PciInfo PciInfo;

typedef struct PciInfoList PciInfoList;

typedef struct PciMemoryRange PciMemoryRange;

typedef struct PciMemoryRegion PciMemoryRegion;

typedef struct PciMemoryRegionList PciMemoryRegionList;

typedef enum PreallocMode {
    PREALLOC_MODE_OFF = 0,
    PREALLOC_MODE_METADATA = 1,
    PREALLOC_MODE_FALLOC = 2,
    PREALLOC_MODE_FULL = 3,
    PREALLOC_MODE_MAX = 4,
} PreallocMode;

extern const char *const PreallocMode_lookup[];

typedef enum QCryptoTLSCredsEndpoint {
    QCRYPTO_TLS_CREDS_ENDPOINT_CLIENT = 0,
    QCRYPTO_TLS_CREDS_ENDPOINT_SERVER = 1,
    QCRYPTO_TLS_CREDS_ENDPOINT_MAX = 2,
} QCryptoTLSCredsEndpoint;

extern const char *const QCryptoTLSCredsEndpoint_lookup[];

typedef enum QKeyCode {
    Q_KEY_CODE_UNMAPPED = 0,
    Q_KEY_CODE_SHIFT = 1,
    Q_KEY_CODE_SHIFT_R = 2,
    Q_KEY_CODE_ALT = 3,
    Q_KEY_CODE_ALT_R = 4,
    Q_KEY_CODE_ALTGR = 5,
    Q_KEY_CODE_ALTGR_R = 6,
    Q_KEY_CODE_CTRL = 7,
    Q_KEY_CODE_CTRL_R = 8,
    Q_KEY_CODE_MENU = 9,
    Q_KEY_CODE_ESC = 10,
    Q_KEY_CODE_1 = 11,
    Q_KEY_CODE_2 = 12,
    Q_KEY_CODE_3 = 13,
    Q_KEY_CODE_4 = 14,
    Q_KEY_CODE_5 = 15,
    Q_KEY_CODE_6 = 16,
    Q_KEY_CODE_7 = 17,
    Q_KEY_CODE_8 = 18,
    Q_KEY_CODE_9 = 19,
    Q_KEY_CODE_0 = 20,
    Q_KEY_CODE_MINUS = 21,
    Q_KEY_CODE_EQUAL = 22,
    Q_KEY_CODE_BACKSPACE = 23,
    Q_KEY_CODE_TAB = 24,
    Q_KEY_CODE_Q = 25,
    Q_KEY_CODE_W = 26,
    Q_KEY_CODE_E = 27,
    Q_KEY_CODE_R = 28,
    Q_KEY_CODE_T = 29,
    Q_KEY_CODE_Y = 30,
    Q_KEY_CODE_U = 31,
    Q_KEY_CODE_I = 32,
    Q_KEY_CODE_O = 33,
    Q_KEY_CODE_P = 34,
    Q_KEY_CODE_BRACKET_LEFT = 35,
    Q_KEY_CODE_BRACKET_RIGHT = 36,
    Q_KEY_CODE_RET = 37,
    Q_KEY_CODE_A = 38,
    Q_KEY_CODE_S = 39,
    Q_KEY_CODE_D = 40,
    Q_KEY_CODE_F = 41,
    Q_KEY_CODE_G = 42,
    Q_KEY_CODE_H = 43,
    Q_KEY_CODE_J = 44,
    Q_KEY_CODE_K = 45,
    Q_KEY_CODE_L = 46,
    Q_KEY_CODE_SEMICOLON = 47,
    Q_KEY_CODE_APOSTROPHE = 48,
    Q_KEY_CODE_GRAVE_ACCENT = 49,
    Q_KEY_CODE_BACKSLASH = 50,
    Q_KEY_CODE_Z = 51,
    Q_KEY_CODE_X = 52,
    Q_KEY_CODE_C = 53,
    Q_KEY_CODE_V = 54,
    Q_KEY_CODE_B = 55,
    Q_KEY_CODE_N = 56,
    Q_KEY_CODE_M = 57,
    Q_KEY_CODE_COMMA = 58,
    Q_KEY_CODE_DOT = 59,
    Q_KEY_CODE_SLASH = 60,
    Q_KEY_CODE_ASTERISK = 61,
    Q_KEY_CODE_SPC = 62,
    Q_KEY_CODE_CAPS_LOCK = 63,
    Q_KEY_CODE_F1 = 64,
    Q_KEY_CODE_F2 = 65,
    Q_KEY_CODE_F3 = 66,
    Q_KEY_CODE_F4 = 67,
    Q_KEY_CODE_F5 = 68,
    Q_KEY_CODE_F6 = 69,
    Q_KEY_CODE_F7 = 70,
    Q_KEY_CODE_F8 = 71,
    Q_KEY_CODE_F9 = 72,
    Q_KEY_CODE_F10 = 73,
    Q_KEY_CODE_NUM_LOCK = 74,
    Q_KEY_CODE_SCROLL_LOCK = 75,
    Q_KEY_CODE_KP_DIVIDE = 76,
    Q_KEY_CODE_KP_MULTIPLY = 77,
    Q_KEY_CODE_KP_SUBTRACT = 78,
    Q_KEY_CODE_KP_ADD = 79,
    Q_KEY_CODE_KP_ENTER = 80,
    Q_KEY_CODE_KP_DECIMAL = 81,
    Q_KEY_CODE_SYSRQ = 82,
    Q_KEY_CODE_KP_0 = 83,
    Q_KEY_CODE_KP_1 = 84,
    Q_KEY_CODE_KP_2 = 85,
    Q_KEY_CODE_KP_3 = 86,
    Q_KEY_CODE_KP_4 = 87,
    Q_KEY_CODE_KP_5 = 88,
    Q_KEY_CODE_KP_6 = 89,
    Q_KEY_CODE_KP_7 = 90,
    Q_KEY_CODE_KP_8 = 91,
    Q_KEY_CODE_KP_9 = 92,
    Q_KEY_CODE_LESS = 93,
    Q_KEY_CODE_F11 = 94,
    Q_KEY_CODE_F12 = 95,
    Q_KEY_CODE_PRINT = 96,
    Q_KEY_CODE_HOME = 97,
    Q_KEY_CODE_PGUP = 98,
    Q_KEY_CODE_PGDN = 99,
    Q_KEY_CODE_END = 100,
    Q_KEY_CODE_LEFT = 101,
    Q_KEY_CODE_UP = 102,
    Q_KEY_CODE_DOWN = 103,
    Q_KEY_CODE_RIGHT = 104,
    Q_KEY_CODE_INSERT = 105,
    Q_KEY_CODE_DELETE = 106,
    Q_KEY_CODE_STOP = 107,
    Q_KEY_CODE_AGAIN = 108,
    Q_KEY_CODE_PROPS = 109,
    Q_KEY_CODE_UNDO = 110,
    Q_KEY_CODE_FRONT = 111,
    Q_KEY_CODE_COPY = 112,
    Q_KEY_CODE_OPEN = 113,
    Q_KEY_CODE_PASTE = 114,
    Q_KEY_CODE_FIND = 115,
    Q_KEY_CODE_CUT = 116,
    Q_KEY_CODE_LF = 117,
    Q_KEY_CODE_HELP = 118,
    Q_KEY_CODE_META_L = 119,
    Q_KEY_CODE_META_R = 120,
    Q_KEY_CODE_COMPOSE = 121,
    Q_KEY_CODE_PAUSE = 122,
    Q_KEY_CODE_RO = 123,
    Q_KEY_CODE_KP_COMMA = 124,
    Q_KEY_CODE_MAX = 125,
} QKeyCode;

extern const char *const QKeyCode_lookup[];

typedef struct Qcow2OverlapCheckFlags Qcow2OverlapCheckFlags;

typedef enum Qcow2OverlapCheckMode {
    QCOW2_OVERLAP_CHECK_MODE_NONE = 0,
    QCOW2_OVERLAP_CHECK_MODE_CONSTANT = 1,
    QCOW2_OVERLAP_CHECK_MODE_CACHED = 2,
    QCOW2_OVERLAP_CHECK_MODE_ALL = 3,
    QCOW2_OVERLAP_CHECK_MODE_MAX = 4,
} Qcow2OverlapCheckMode;

extern const char *const Qcow2OverlapCheckMode_lookup[];

typedef struct Qcow2OverlapChecks Qcow2OverlapChecks;

typedef enum Qcow2OverlapChecksKind {
    QCOW2_OVERLAP_CHECKS_KIND_FLAGS = 0,
    QCOW2_OVERLAP_CHECKS_KIND_MODE = 1,
    QCOW2_OVERLAP_CHECKS_KIND_MAX = 2,
} Qcow2OverlapChecksKind;

extern const char *const Qcow2OverlapChecksKind_lookup[];

typedef enum QuorumReadPattern {
    QUORUM_READ_PATTERN_QUORUM = 0,
    QUORUM_READ_PATTERN_FIFO = 1,
    QUORUM_READ_PATTERN_MAX = 2,
} QuorumReadPattern;

extern const char *const QuorumReadPattern_lookup[];

typedef enum ReplayMode {
    REPLAY_MODE_NONE = 0,
    REPLAY_MODE_RECORD = 1,
    REPLAY_MODE_PLAY = 2,
    REPLAY_MODE_MAX = 3,
} ReplayMode;

extern const char *const ReplayMode_lookup[];

typedef struct RockerOfDpaFlow RockerOfDpaFlow;

typedef struct RockerOfDpaFlowAction RockerOfDpaFlowAction;

typedef struct RockerOfDpaFlowKey RockerOfDpaFlowKey;

typedef struct RockerOfDpaFlowList RockerOfDpaFlowList;

typedef struct RockerOfDpaFlowMask RockerOfDpaFlowMask;

typedef struct RockerOfDpaGroup RockerOfDpaGroup;

typedef struct RockerOfDpaGroupList RockerOfDpaGroupList;

typedef struct RockerPort RockerPort;

typedef enum RockerPortAutoneg {
    ROCKER_PORT_AUTONEG_OFF = 0,
    ROCKER_PORT_AUTONEG_ON = 1,
    ROCKER_PORT_AUTONEG_MAX = 2,
} RockerPortAutoneg;

extern const char *const RockerPortAutoneg_lookup[];

typedef enum RockerPortDuplex {
    ROCKER_PORT_DUPLEX_HALF = 0,
    ROCKER_PORT_DUPLEX_FULL = 1,
    ROCKER_PORT_DUPLEX_MAX = 2,
} RockerPortDuplex;

extern const char *const RockerPortDuplex_lookup[];

typedef struct RockerPortList RockerPortList;

typedef struct RockerSwitch RockerSwitch;

typedef enum RunState {
    RUN_STATE_DEBUG = 0,
    RUN_STATE_INMIGRATE = 1,
    RUN_STATE_INTERNAL_ERROR = 2,
    RUN_STATE_IO_ERROR = 3,
    RUN_STATE_PAUSED = 4,
    RUN_STATE_POSTMIGRATE = 5,
    RUN_STATE_PRELAUNCH = 6,
    RUN_STATE_FINISH_MIGRATE = 7,
    RUN_STATE_RESTORE_VM = 8,
    RUN_STATE_RUNNING = 9,
    RUN_STATE_SAVE_VM = 10,
    RUN_STATE_SHUTDOWN = 11,
    RUN_STATE_SUSPENDED = 12,
    RUN_STATE_WATCHDOG = 13,
    RUN_STATE_GUEST_PANICKED = 14,
    RUN_STATE_MAX = 15,
} RunState;

extern const char *const RunState_lookup[];

typedef struct RxFilterInfo RxFilterInfo;

typedef struct RxFilterInfoList RxFilterInfoList;

typedef enum RxState {
    RX_STATE_NORMAL = 0,
    RX_STATE_NONE = 1,
    RX_STATE_ALL = 2,
    RX_STATE_MAX = 3,
} RxState;

extern const char *const RxState_lookup[];

typedef struct SchemaInfo SchemaInfo;

typedef struct SchemaInfoAlternate SchemaInfoAlternate;

typedef struct SchemaInfoAlternateMember SchemaInfoAlternateMember;

typedef struct SchemaInfoAlternateMemberList SchemaInfoAlternateMemberList;

typedef struct SchemaInfoArray SchemaInfoArray;

typedef struct SchemaInfoBase SchemaInfoBase;

typedef struct SchemaInfoBuiltin SchemaInfoBuiltin;

typedef struct SchemaInfoCommand SchemaInfoCommand;

typedef struct SchemaInfoEnum SchemaInfoEnum;

typedef struct SchemaInfoEvent SchemaInfoEvent;

typedef struct SchemaInfoList SchemaInfoList;

typedef struct SchemaInfoObject SchemaInfoObject;

typedef struct SchemaInfoObjectMember SchemaInfoObjectMember;

typedef struct SchemaInfoObjectMemberList SchemaInfoObjectMemberList;

typedef struct SchemaInfoObjectVariant SchemaInfoObjectVariant;

typedef struct SchemaInfoObjectVariantList SchemaInfoObjectVariantList;

typedef enum SchemaMetaType {
    SCHEMA_META_TYPE_BUILTIN = 0,
    SCHEMA_META_TYPE_ENUM = 1,
    SCHEMA_META_TYPE_ARRAY = 2,
    SCHEMA_META_TYPE_OBJECT = 3,
    SCHEMA_META_TYPE_ALTERNATE = 4,
    SCHEMA_META_TYPE_COMMAND = 5,
    SCHEMA_META_TYPE_EVENT = 6,
    SCHEMA_META_TYPE_MAX = 7,
} SchemaMetaType;

extern const char *const SchemaMetaType_lookup[];

typedef struct SnapshotInfo SnapshotInfo;

typedef struct SnapshotInfoList SnapshotInfoList;

typedef struct SocketAddress SocketAddress;

typedef enum SocketAddressKind {
    SOCKET_ADDRESS_KIND_INET = 0,
    SOCKET_ADDRESS_KIND_UNIX = 1,
    SOCKET_ADDRESS_KIND_FD = 2,
    SOCKET_ADDRESS_KIND_MAX = 3,
} SocketAddressKind;

extern const char *const SocketAddressKind_lookup[];

typedef struct SpiceBasicInfo SpiceBasicInfo;

typedef struct SpiceChannel SpiceChannel;

typedef struct SpiceChannelList SpiceChannelList;

typedef struct SpiceInfo SpiceInfo;

typedef enum SpiceQueryMouseMode {
    SPICE_QUERY_MOUSE_MODE_CLIENT = 0,
    SPICE_QUERY_MOUSE_MODE_SERVER = 1,
    SPICE_QUERY_MOUSE_MODE_UNKNOWN = 2,
    SPICE_QUERY_MOUSE_MODE_MAX = 3,
} SpiceQueryMouseMode;

extern const char *const SpiceQueryMouseMode_lookup[];

typedef struct SpiceServerInfo SpiceServerInfo;

typedef struct StatusInfo StatusInfo;

typedef struct String String;

typedef struct StringList StringList;

typedef struct TPMInfo TPMInfo;

typedef struct TPMInfoList TPMInfoList;

typedef struct TPMPassthroughOptions TPMPassthroughOptions;

typedef struct TargetInfo TargetInfo;

typedef enum TpmModel {
    TPM_MODEL_TPM_TIS = 0,
    TPM_MODEL_MAX = 1,
} TpmModel;

extern const char *const TpmModel_lookup[];

typedef struct TpmModelList TpmModelList;

typedef enum TpmType {
    TPM_TYPE_PASSTHROUGH = 0,
    TPM_TYPE_MAX = 1,
} TpmType;

extern const char *const TpmType_lookup[];

typedef struct TpmTypeList TpmTypeList;

typedef struct TpmTypeOptions TpmTypeOptions;

typedef enum TpmTypeOptionsKind {
    TPM_TYPE_OPTIONS_KIND_PASSTHROUGH = 0,
    TPM_TYPE_OPTIONS_KIND_MAX = 1,
} TpmTypeOptionsKind;

extern const char *const TpmTypeOptionsKind_lookup[];

typedef struct TraceEventInfo TraceEventInfo;

typedef struct TraceEventInfoList TraceEventInfoList;

typedef enum TraceEventState {
    TRACE_EVENT_STATE_UNAVAILABLE = 0,
    TRACE_EVENT_STATE_DISABLED = 1,
    TRACE_EVENT_STATE_ENABLED = 2,
    TRACE_EVENT_STATE_MAX = 3,
} TraceEventState;

extern const char *const TraceEventState_lookup[];

typedef struct TransactionAction TransactionAction;

typedef enum TransactionActionKind {
    TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT = 0,
    TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT_SYNC = 1,
    TRANSACTION_ACTION_KIND_DRIVE_BACKUP = 2,
    TRANSACTION_ACTION_KIND_BLOCKDEV_BACKUP = 3,
    TRANSACTION_ACTION_KIND_ABORT = 4,
    TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT_INTERNAL_SYNC = 5,
    TRANSACTION_ACTION_KIND_BLOCK_DIRTY_BITMAP_ADD = 6,
    TRANSACTION_ACTION_KIND_BLOCK_DIRTY_BITMAP_CLEAR = 7,
    TRANSACTION_ACTION_KIND_MAX = 8,
} TransactionActionKind;

extern const char *const TransactionActionKind_lookup[];

typedef struct TransactionActionList TransactionActionList;

typedef struct TransactionProperties TransactionProperties;

typedef struct UnixSocketAddress UnixSocketAddress;

typedef struct UuidInfo UuidInfo;

typedef struct VersionInfo VersionInfo;

typedef struct VersionTriple VersionTriple;

typedef struct VncBasicInfo VncBasicInfo;

typedef struct VncBasicInfoList VncBasicInfoList;

typedef struct VncClientInfo VncClientInfo;

typedef struct VncClientInfoList VncClientInfoList;

typedef struct VncInfo VncInfo;

typedef struct VncInfo2 VncInfo2;

typedef struct VncInfo2List VncInfo2List;

typedef enum VncPrimaryAuth {
    VNC_PRIMARY_AUTH_NONE = 0,
    VNC_PRIMARY_AUTH_VNC = 1,
    VNC_PRIMARY_AUTH_RA2 = 2,
    VNC_PRIMARY_AUTH_RA2NE = 3,
    VNC_PRIMARY_AUTH_TIGHT = 4,
    VNC_PRIMARY_AUTH_ULTRA = 5,
    VNC_PRIMARY_AUTH_TLS = 6,
    VNC_PRIMARY_AUTH_VENCRYPT = 7,
    VNC_PRIMARY_AUTH_SASL = 8,
    VNC_PRIMARY_AUTH_MAX = 9,
} VncPrimaryAuth;

extern const char *const VncPrimaryAuth_lookup[];

typedef struct VncServerInfo VncServerInfo;

typedef enum VncVencryptSubAuth {
    VNC_VENCRYPT_SUB_AUTH_PLAIN = 0,
    VNC_VENCRYPT_SUB_AUTH_TLS_NONE = 1,
    VNC_VENCRYPT_SUB_AUTH_X509_NONE = 2,
    VNC_VENCRYPT_SUB_AUTH_TLS_VNC = 3,
    VNC_VENCRYPT_SUB_AUTH_X509_VNC = 4,
    VNC_VENCRYPT_SUB_AUTH_TLS_PLAIN = 5,
    VNC_VENCRYPT_SUB_AUTH_X509_PLAIN = 6,
    VNC_VENCRYPT_SUB_AUTH_TLS_SASL = 7,
    VNC_VENCRYPT_SUB_AUTH_X509_SASL = 8,
    VNC_VENCRYPT_SUB_AUTH_MAX = 9,
} VncVencryptSubAuth;

extern const char *const VncVencryptSubAuth_lookup[];

typedef enum WatchdogExpirationAction {
    WATCHDOG_EXPIRATION_ACTION_RESET = 0,
    WATCHDOG_EXPIRATION_ACTION_SHUTDOWN = 1,
    WATCHDOG_EXPIRATION_ACTION_POWEROFF = 2,
    WATCHDOG_EXPIRATION_ACTION_PAUSE = 3,
    WATCHDOG_EXPIRATION_ACTION_DEBUG = 4,
    WATCHDOG_EXPIRATION_ACTION_NONE = 5,
    WATCHDOG_EXPIRATION_ACTION_INJECT_NMI = 6,
    WATCHDOG_EXPIRATION_ACTION_MAX = 7,
} WatchdogExpirationAction;

extern const char *const WatchdogExpirationAction_lookup[];

typedef struct X86CPUFeatureWordInfo X86CPUFeatureWordInfo;

typedef struct X86CPUFeatureWordInfoList X86CPUFeatureWordInfoList;

typedef enum X86CPURegister32 {
    X86_CPU_REGISTER32_EAX = 0,
    X86_CPU_REGISTER32_EBX = 1,
    X86_CPU_REGISTER32_ECX = 2,
    X86_CPU_REGISTER32_EDX = 3,
    X86_CPU_REGISTER32_ESP = 4,
    X86_CPU_REGISTER32_EBP = 5,
    X86_CPU_REGISTER32_ESI = 6,
    X86_CPU_REGISTER32_EDI = 7,
    X86_CPU_REGISTER32_MAX = 8,
} X86CPURegister32;

extern const char *const X86CPURegister32_lookup[];

typedef struct XBZRLECacheStats XBZRLECacheStats;

struct ACPIOSTInfo {
    bool has_device;
    char *device;
    char *slot;
    ACPISlotType slot_type;
    int64_t source;
    int64_t status;
};

void qapi_free_ACPIOSTInfo(ACPIOSTInfo *obj);

struct ACPIOSTInfoList {
    union {
        ACPIOSTInfo *value;
        uint64_t padding;
    };
    ACPIOSTInfoList *next;
};

void qapi_free_ACPIOSTInfoList(ACPIOSTInfoList *obj);

struct Abort {
    char qapi_dummy_field_for_empty_struct;
};

void qapi_free_Abort(Abort *obj);

struct AcpiTableOptions {
    bool has_sig;
    char *sig;
    bool has_rev;
    uint8_t rev;
    bool has_oem_id;
    char *oem_id;
    bool has_oem_table_id;
    char *oem_table_id;
    bool has_oem_rev;
    uint32_t oem_rev;
    bool has_asl_compiler_id;
    char *asl_compiler_id;
    bool has_asl_compiler_rev;
    uint32_t asl_compiler_rev;
    bool has_file;
    char *file;
    bool has_data;
    char *data;
};

void qapi_free_AcpiTableOptions(AcpiTableOptions *obj);

struct AddfdInfo {
    int64_t fdset_id;
    int64_t fd;
};

void qapi_free_AddfdInfo(AddfdInfo *obj);

struct BalloonInfo {
    int64_t actual;
};

void qapi_free_BalloonInfo(BalloonInfo *obj);

struct BlkdebugInjectErrorOptions {
    BlkdebugEvent event;
    bool has_state;
    int64_t state;
    bool has_q_errno;
    int64_t q_errno;
    bool has_sector;
    int64_t sector;
    bool has_once;
    bool once;
    bool has_immediately;
    bool immediately;
};

void qapi_free_BlkdebugInjectErrorOptions(BlkdebugInjectErrorOptions *obj);

struct BlkdebugInjectErrorOptionsList {
    union {
        BlkdebugInjectErrorOptions *value;
        uint64_t padding;
    };
    BlkdebugInjectErrorOptionsList *next;
};

void qapi_free_BlkdebugInjectErrorOptionsList(BlkdebugInjectErrorOptionsList *obj);

struct BlkdebugSetStateOptions {
    BlkdebugEvent event;
    bool has_state;
    int64_t state;
    int64_t new_state;
};

void qapi_free_BlkdebugSetStateOptions(BlkdebugSetStateOptions *obj);

struct BlkdebugSetStateOptionsList {
    union {
        BlkdebugSetStateOptions *value;
        uint64_t padding;
    };
    BlkdebugSetStateOptionsList *next;
};

void qapi_free_BlkdebugSetStateOptionsList(BlkdebugSetStateOptionsList *obj);

struct BlockDeviceInfo {
    char *file;
    bool has_node_name;
    char *node_name;
    bool ro;
    char *drv;
    bool has_backing_file;
    char *backing_file;
    int64_t backing_file_depth;
    bool encrypted;
    bool encryption_key_missing;
    BlockdevDetectZeroesOptions detect_zeroes;
    int64_t bps;
    int64_t bps_rd;
    int64_t bps_wr;
    int64_t iops;
    int64_t iops_rd;
    int64_t iops_wr;
    ImageInfo *image;
    bool has_bps_max;
    int64_t bps_max;
    bool has_bps_rd_max;
    int64_t bps_rd_max;
    bool has_bps_wr_max;
    int64_t bps_wr_max;
    bool has_iops_max;
    int64_t iops_max;
    bool has_iops_rd_max;
    int64_t iops_rd_max;
    bool has_iops_wr_max;
    int64_t iops_wr_max;
    bool has_iops_size;
    int64_t iops_size;
    bool has_group;
    char *group;
    BlockdevCacheInfo *cache;
    int64_t write_threshold;
};

void qapi_free_BlockDeviceInfo(BlockDeviceInfo *obj);

struct BlockDeviceInfoList {
    union {
        BlockDeviceInfo *value;
        uint64_t padding;
    };
    BlockDeviceInfoList *next;
};

void qapi_free_BlockDeviceInfoList(BlockDeviceInfoList *obj);

struct BlockDeviceMapEntry {
    int64_t start;
    int64_t length;
    int64_t depth;
    bool zero;
    bool data;
    bool has_offset;
    int64_t offset;
};

void qapi_free_BlockDeviceMapEntry(BlockDeviceMapEntry *obj);

struct BlockDeviceStats {
    int64_t rd_bytes;
    int64_t wr_bytes;
    int64_t rd_operations;
    int64_t wr_operations;
    int64_t flush_operations;
    int64_t flush_total_time_ns;
    int64_t wr_total_time_ns;
    int64_t rd_total_time_ns;
    int64_t wr_highest_offset;
    int64_t rd_merged;
    int64_t wr_merged;
    bool has_idle_time_ns;
    int64_t idle_time_ns;
    int64_t failed_rd_operations;
    int64_t failed_wr_operations;
    int64_t failed_flush_operations;
    int64_t invalid_rd_operations;
    int64_t invalid_wr_operations;
    int64_t invalid_flush_operations;
    bool account_invalid;
    bool account_failed;
    BlockDeviceTimedStatsList *timed_stats;
};

void qapi_free_BlockDeviceStats(BlockDeviceStats *obj);

struct BlockDeviceTimedStats {
    int64_t interval_length;
    int64_t min_rd_latency_ns;
    int64_t max_rd_latency_ns;
    int64_t avg_rd_latency_ns;
    int64_t min_wr_latency_ns;
    int64_t max_wr_latency_ns;
    int64_t avg_wr_latency_ns;
    int64_t min_flush_latency_ns;
    int64_t max_flush_latency_ns;
    int64_t avg_flush_latency_ns;
    double avg_rd_queue_depth;
    double avg_wr_queue_depth;
};

void qapi_free_BlockDeviceTimedStats(BlockDeviceTimedStats *obj);

struct BlockDeviceTimedStatsList {
    union {
        BlockDeviceTimedStats *value;
        uint64_t padding;
    };
    BlockDeviceTimedStatsList *next;
};

void qapi_free_BlockDeviceTimedStatsList(BlockDeviceTimedStatsList *obj);

struct BlockDirtyBitmap {
    char *node;
    char *name;
};

void qapi_free_BlockDirtyBitmap(BlockDirtyBitmap *obj);

struct BlockDirtyBitmapAdd {
    char *node;
    char *name;
    bool has_granularity;
    uint32_t granularity;
};

void qapi_free_BlockDirtyBitmapAdd(BlockDirtyBitmapAdd *obj);

struct BlockDirtyInfo {
    bool has_name;
    char *name;
    int64_t count;
    uint32_t granularity;
    DirtyBitmapStatus status;
};

void qapi_free_BlockDirtyInfo(BlockDirtyInfo *obj);

struct BlockDirtyInfoList {
    union {
        BlockDirtyInfo *value;
        uint64_t padding;
    };
    BlockDirtyInfoList *next;
};

void qapi_free_BlockDirtyInfoList(BlockDirtyInfoList *obj);

struct BlockInfo {
    char *device;
    char *type;
    bool removable;
    bool locked;
    bool has_inserted;
    BlockDeviceInfo *inserted;
    bool has_tray_open;
    bool tray_open;
    bool has_io_status;
    BlockDeviceIoStatus io_status;
    bool has_dirty_bitmaps;
    BlockDirtyInfoList *dirty_bitmaps;
};

void qapi_free_BlockInfo(BlockInfo *obj);

struct BlockInfoList {
    union {
        BlockInfo *value;
        uint64_t padding;
    };
    BlockInfoList *next;
};

void qapi_free_BlockInfoList(BlockInfoList *obj);

struct BlockJobInfo {
    char *type;
    char *device;
    int64_t len;
    int64_t offset;
    bool busy;
    bool paused;
    int64_t speed;
    BlockDeviceIoStatus io_status;
    bool ready;
};

void qapi_free_BlockJobInfo(BlockJobInfo *obj);

struct BlockJobInfoList {
    union {
        BlockJobInfo *value;
        uint64_t padding;
    };
    BlockJobInfoList *next;
};

void qapi_free_BlockJobInfoList(BlockJobInfoList *obj);

struct BlockStats {
    bool has_device;
    char *device;
    bool has_node_name;
    char *node_name;
    BlockDeviceStats *stats;
    bool has_parent;
    BlockStats *parent;
    bool has_backing;
    BlockStats *backing;
};

void qapi_free_BlockStats(BlockStats *obj);

struct BlockStatsList {
    union {
        BlockStats *value;
        uint64_t padding;
    };
    BlockStatsList *next;
};

void qapi_free_BlockStatsList(BlockStatsList *obj);

struct BlockdevBackup {
    char *device;
    char *target;
    MirrorSyncMode sync;
    bool has_speed;
    int64_t speed;
    bool has_on_source_error;
    BlockdevOnError on_source_error;
    bool has_on_target_error;
    BlockdevOnError on_target_error;
};

void qapi_free_BlockdevBackup(BlockdevBackup *obj);

struct BlockdevCacheInfo {
    bool writeback;
    bool direct;
    bool no_flush;
};

void qapi_free_BlockdevCacheInfo(BlockdevCacheInfo *obj);

struct BlockdevCacheOptions {
    bool has_writeback;
    bool writeback;
    bool has_direct;
    bool direct;
    bool has_no_flush;
    bool no_flush;
};

void qapi_free_BlockdevCacheOptions(BlockdevCacheOptions *obj);

struct BlockdevOptions {
    /* Members inherited from BlockdevOptionsBase: */
    BlockdevDriver driver;
    bool has_id;
    char *id;
    bool has_node_name;
    char *node_name;
    bool has_discard;
    BlockdevDiscardOptions discard;
    bool has_cache;
    BlockdevCacheOptions *cache;
    bool has_aio;
    BlockdevAioOptions aio;
    bool has_rerror;
    BlockdevOnError rerror;
    bool has_werror;
    BlockdevOnError werror;
    bool has_read_only;
    bool read_only;
    bool has_stats_account_invalid;
    bool stats_account_invalid;
    bool has_stats_account_failed;
    bool stats_account_failed;
    bool has_stats_intervals;
    intList *stats_intervals;
    bool has_detect_zeroes;
    BlockdevDetectZeroesOptions detect_zeroes;
    /* Own members: */
    union { /* union tag is @driver */
        void *data;
        BlockdevOptionsArchipelago *archipelago;
        BlockdevOptionsBlkdebug *blkdebug;
        BlockdevOptionsBlkverify *blkverify;
        BlockdevOptionsGenericFormat *bochs;
        BlockdevOptionsGenericFormat *cloop;
        BlockdevOptionsGenericFormat *dmg;
        BlockdevOptionsFile *file;
        BlockdevOptionsFile *ftp;
        BlockdevOptionsFile *ftps;
        BlockdevOptionsFile *host_cdrom;
        BlockdevOptionsFile *host_device;
        BlockdevOptionsFile *http;
        BlockdevOptionsFile *https;
        BlockdevOptionsNull *null_aio;
        BlockdevOptionsNull *null_co;
        BlockdevOptionsGenericFormat *parallels;
        BlockdevOptionsQcow2 *qcow2;
        BlockdevOptionsGenericCOWFormat *qcow;
        BlockdevOptionsGenericCOWFormat *qed;
        BlockdevOptionsQuorum *quorum;
        BlockdevOptionsGenericFormat *raw;
        BlockdevOptionsFile *tftp;
        BlockdevOptionsGenericFormat *vdi;
        BlockdevOptionsGenericFormat *vhdx;
        BlockdevOptionsGenericCOWFormat *vmdk;
        BlockdevOptionsGenericFormat *vpc;
        BlockdevOptionsVVFAT *vvfat;
    } u;
};

static inline BlockdevOptionsBase *qapi_BlockdevOptions_base(const BlockdevOptions *obj)
{
    return (BlockdevOptionsBase *)obj;
}

void qapi_free_BlockdevOptions(BlockdevOptions *obj);

struct BlockdevOptionsArchipelago {
    char *volume;
    bool has_mport;
    int64_t mport;
    bool has_vport;
    int64_t vport;
    bool has_segment;
    char *segment;
};

void qapi_free_BlockdevOptionsArchipelago(BlockdevOptionsArchipelago *obj);

struct BlockdevOptionsBase {
    BlockdevDriver driver;
    bool has_id;
    char *id;
    bool has_node_name;
    char *node_name;
    bool has_discard;
    BlockdevDiscardOptions discard;
    bool has_cache;
    BlockdevCacheOptions *cache;
    bool has_aio;
    BlockdevAioOptions aio;
    bool has_rerror;
    BlockdevOnError rerror;
    bool has_werror;
    BlockdevOnError werror;
    bool has_read_only;
    bool read_only;
    bool has_stats_account_invalid;
    bool stats_account_invalid;
    bool has_stats_account_failed;
    bool stats_account_failed;
    bool has_stats_intervals;
    intList *stats_intervals;
    bool has_detect_zeroes;
    BlockdevDetectZeroesOptions detect_zeroes;
};

void qapi_free_BlockdevOptionsBase(BlockdevOptionsBase *obj);

struct BlockdevOptionsBlkdebug {
    BlockdevRef *image;
    bool has_config;
    char *config;
    bool has_align;
    int64_t align;
    bool has_inject_error;
    BlkdebugInjectErrorOptionsList *inject_error;
    bool has_set_state;
    BlkdebugSetStateOptionsList *set_state;
};

void qapi_free_BlockdevOptionsBlkdebug(BlockdevOptionsBlkdebug *obj);

struct BlockdevOptionsBlkverify {
    BlockdevRef *test;
    BlockdevRef *raw;
};

void qapi_free_BlockdevOptionsBlkverify(BlockdevOptionsBlkverify *obj);

struct BlockdevOptionsFile {
    char *filename;
};

void qapi_free_BlockdevOptionsFile(BlockdevOptionsFile *obj);

struct BlockdevOptionsGenericCOWFormat {
    /* Members inherited from BlockdevOptionsGenericFormat: */
    BlockdevRef *file;
    /* Own members: */
    bool has_backing;
    BlockdevRef *backing;
};

static inline BlockdevOptionsGenericFormat *qapi_BlockdevOptionsGenericCOWFormat_base(const BlockdevOptionsGenericCOWFormat *obj)
{
    return (BlockdevOptionsGenericFormat *)obj;
}

void qapi_free_BlockdevOptionsGenericCOWFormat(BlockdevOptionsGenericCOWFormat *obj);

struct BlockdevOptionsGenericFormat {
    BlockdevRef *file;
};

void qapi_free_BlockdevOptionsGenericFormat(BlockdevOptionsGenericFormat *obj);

struct BlockdevOptionsNull {
    bool has_size;
    int64_t size;
    bool has_latency_ns;
    uint64_t latency_ns;
};

void qapi_free_BlockdevOptionsNull(BlockdevOptionsNull *obj);

struct BlockdevOptionsQcow2 {
    /* Members inherited from BlockdevOptionsGenericCOWFormat: */
    BlockdevRef *file;
    bool has_backing;
    BlockdevRef *backing;
    /* Own members: */
    bool has_lazy_refcounts;
    bool lazy_refcounts;
    bool has_pass_discard_request;
    bool pass_discard_request;
    bool has_pass_discard_snapshot;
    bool pass_discard_snapshot;
    bool has_pass_discard_other;
    bool pass_discard_other;
    bool has_overlap_check;
    Qcow2OverlapChecks *overlap_check;
    bool has_cache_size;
    int64_t cache_size;
    bool has_l2_cache_size;
    int64_t l2_cache_size;
    bool has_refcount_cache_size;
    int64_t refcount_cache_size;
    bool has_cache_clean_interval;
    int64_t cache_clean_interval;
};

static inline BlockdevOptionsGenericCOWFormat *qapi_BlockdevOptionsQcow2_base(const BlockdevOptionsQcow2 *obj)
{
    return (BlockdevOptionsGenericCOWFormat *)obj;
}

void qapi_free_BlockdevOptionsQcow2(BlockdevOptionsQcow2 *obj);

struct BlockdevOptionsQuorum {
    bool has_blkverify;
    bool blkverify;
    BlockdevRefList *children;
    int64_t vote_threshold;
    bool has_rewrite_corrupted;
    bool rewrite_corrupted;
    bool has_read_pattern;
    QuorumReadPattern read_pattern;
};

void qapi_free_BlockdevOptionsQuorum(BlockdevOptionsQuorum *obj);

struct BlockdevOptionsVVFAT {
    char *dir;
    bool has_fat_type;
    int64_t fat_type;
    bool has_floppy;
    bool floppy;
    bool has_label;
    char *label;
    bool has_rw;
    bool rw;
};

void qapi_free_BlockdevOptionsVVFAT(BlockdevOptionsVVFAT *obj);

struct BlockdevRef {
    BlockdevRefKind type;
    union { /* union tag is @type */
        void *data;
        BlockdevOptions *definition;
        char *reference;
    } u;
};

extern const int BlockdevRef_qtypes[];

void qapi_free_BlockdevRef(BlockdevRef *obj);

struct BlockdevRefList {
    union {
        BlockdevRef *value;
        uint64_t padding;
    };
    BlockdevRefList *next;
};

void qapi_free_BlockdevRefList(BlockdevRefList *obj);

struct BlockdevSnapshot {
    char *node;
    char *overlay;
};

void qapi_free_BlockdevSnapshot(BlockdevSnapshot *obj);

struct BlockdevSnapshotInternal {
    char *device;
    char *name;
};

void qapi_free_BlockdevSnapshotInternal(BlockdevSnapshotInternal *obj);

struct BlockdevSnapshotSync {
    bool has_device;
    char *device;
    bool has_node_name;
    char *node_name;
    char *snapshot_file;
    bool has_snapshot_node_name;
    char *snapshot_node_name;
    bool has_format;
    char *format;
    bool has_mode;
    NewImageMode mode;
};

void qapi_free_BlockdevSnapshotSync(BlockdevSnapshotSync *obj);

struct ChardevBackend {
    ChardevBackendKind type;
    union { /* union tag is @type */
        void *data;
        ChardevFile *file;
        ChardevHostdev *serial;
        ChardevHostdev *parallel;
        ChardevHostdev *pipe;
        ChardevSocket *socket;
        ChardevUdp *udp;
        ChardevDummy *pty;
        ChardevDummy *null;
        ChardevMux *mux;
        ChardevDummy *msmouse;
        ChardevDummy *braille;
        ChardevDummy *testdev;
        ChardevStdio *stdio;
        ChardevDummy *console;
        ChardevSpiceChannel *spicevmc;
        ChardevSpicePort *spiceport;
        ChardevVC *vc;
        ChardevRingbuf *ringbuf;
        ChardevRingbuf *memory;
    } u;
};

void qapi_free_ChardevBackend(ChardevBackend *obj);

struct ChardevBackendInfo {
    char *name;
};

void qapi_free_ChardevBackendInfo(ChardevBackendInfo *obj);

struct ChardevBackendInfoList {
    union {
        ChardevBackendInfo *value;
        uint64_t padding;
    };
    ChardevBackendInfoList *next;
};

void qapi_free_ChardevBackendInfoList(ChardevBackendInfoList *obj);

struct ChardevDummy {
    char qapi_dummy_field_for_empty_struct;
};

void qapi_free_ChardevDummy(ChardevDummy *obj);

struct ChardevFile {
    bool has_in;
    char *in;
    char *out;
};

void qapi_free_ChardevFile(ChardevFile *obj);

struct ChardevHostdev {
    char *device;
};

void qapi_free_ChardevHostdev(ChardevHostdev *obj);

struct ChardevInfo {
    char *label;
    char *filename;
    bool frontend_open;
};

void qapi_free_ChardevInfo(ChardevInfo *obj);

struct ChardevInfoList {
    union {
        ChardevInfo *value;
        uint64_t padding;
    };
    ChardevInfoList *next;
};

void qapi_free_ChardevInfoList(ChardevInfoList *obj);

struct ChardevMux {
    char *chardev;
};

void qapi_free_ChardevMux(ChardevMux *obj);

struct ChardevReturn {
    bool has_pty;
    char *pty;
};

void qapi_free_ChardevReturn(ChardevReturn *obj);

struct ChardevRingbuf {
    bool has_size;
    int64_t size;
};

void qapi_free_ChardevRingbuf(ChardevRingbuf *obj);

struct ChardevSocket {
    SocketAddress *addr;
    bool has_server;
    bool server;
    bool has_wait;
    bool wait;
    bool has_nodelay;
    bool nodelay;
    bool has_telnet;
    bool telnet;
    bool has_reconnect;
    int64_t reconnect;
};

void qapi_free_ChardevSocket(ChardevSocket *obj);

struct ChardevSpiceChannel {
    char *type;
};

void qapi_free_ChardevSpiceChannel(ChardevSpiceChannel *obj);

struct ChardevSpicePort {
    char *fqdn;
};

void qapi_free_ChardevSpicePort(ChardevSpicePort *obj);

struct ChardevStdio {
    bool has_signal;
    bool signal;
};

void qapi_free_ChardevStdio(ChardevStdio *obj);

struct ChardevUdp {
    SocketAddress *remote;
    bool has_local;
    SocketAddress *local;
};

void qapi_free_ChardevUdp(ChardevUdp *obj);

struct ChardevVC {
    bool has_width;
    int64_t width;
    bool has_height;
    int64_t height;
    bool has_cols;
    int64_t cols;
    bool has_rows;
    int64_t rows;
};

void qapi_free_ChardevVC(ChardevVC *obj);

struct CommandInfo {
    char *name;
};

void qapi_free_CommandInfo(CommandInfo *obj);

struct CommandInfoList {
    union {
        CommandInfo *value;
        uint64_t padding;
    };
    CommandInfoList *next;
};

void qapi_free_CommandInfoList(CommandInfoList *obj);

struct CommandLineOptionInfo {
    char *option;
    CommandLineParameterInfoList *parameters;
};

void qapi_free_CommandLineOptionInfo(CommandLineOptionInfo *obj);

struct CommandLineOptionInfoList {
    union {
        CommandLineOptionInfo *value;
        uint64_t padding;
    };
    CommandLineOptionInfoList *next;
};

void qapi_free_CommandLineOptionInfoList(CommandLineOptionInfoList *obj);

struct CommandLineParameterInfo {
    char *name;
    CommandLineParameterType type;
    bool has_help;
    char *help;
    bool has_q_default;
    char *q_default;
};

void qapi_free_CommandLineParameterInfo(CommandLineParameterInfo *obj);

struct CommandLineParameterInfoList {
    union {
        CommandLineParameterInfo *value;
        uint64_t padding;
    };
    CommandLineParameterInfoList *next;
};

void qapi_free_CommandLineParameterInfoList(CommandLineParameterInfoList *obj);

struct CpuDefinitionInfo {
    char *name;
};

void qapi_free_CpuDefinitionInfo(CpuDefinitionInfo *obj);

struct CpuDefinitionInfoList {
    union {
        CpuDefinitionInfo *value;
        uint64_t padding;
    };
    CpuDefinitionInfoList *next;
};

void qapi_free_CpuDefinitionInfoList(CpuDefinitionInfoList *obj);

struct CpuInfo {
    int64_t CPU;
    bool current;
    bool halted;
    char *qom_path;
    bool has_pc;
    int64_t pc;
    bool has_nip;
    int64_t nip;
    bool has_npc;
    int64_t npc;
    bool has_PC;
    int64_t PC;
    int64_t thread_id;
};

void qapi_free_CpuInfo(CpuInfo *obj);

struct CpuInfoList {
    union {
        CpuInfo *value;
        uint64_t padding;
    };
    CpuInfoList *next;
};

void qapi_free_CpuInfoList(CpuInfoList *obj);

struct DevicePropertyInfo {
    char *name;
    char *type;
    bool has_description;
    char *description;
};

void qapi_free_DevicePropertyInfo(DevicePropertyInfo *obj);

struct DevicePropertyInfoList {
    union {
        DevicePropertyInfo *value;
        uint64_t padding;
    };
    DevicePropertyInfoList *next;
};

void qapi_free_DevicePropertyInfoList(DevicePropertyInfoList *obj);

struct DriveBackup {
    char *device;
    char *target;
    bool has_format;
    char *format;
    MirrorSyncMode sync;
    bool has_mode;
    NewImageMode mode;
    bool has_speed;
    int64_t speed;
    bool has_bitmap;
    char *bitmap;
    bool has_on_source_error;
    BlockdevOnError on_source_error;
    bool has_on_target_error;
    BlockdevOnError on_target_error;
};

void qapi_free_DriveBackup(DriveBackup *obj);

struct DummyForceArrays {
    X86CPUFeatureWordInfoList *unused;
};

void qapi_free_DummyForceArrays(DummyForceArrays *obj);

struct DumpGuestMemoryCapability {
    DumpGuestMemoryFormatList *formats;
};

void qapi_free_DumpGuestMemoryCapability(DumpGuestMemoryCapability *obj);

struct DumpGuestMemoryFormatList {
    union {
        DumpGuestMemoryFormat value;
        uint64_t padding;
    };
    DumpGuestMemoryFormatList *next;
};

void qapi_free_DumpGuestMemoryFormatList(DumpGuestMemoryFormatList *obj);

struct EventInfo {
    char *name;
};

void qapi_free_EventInfo(EventInfo *obj);

struct EventInfoList {
    union {
        EventInfo *value;
        uint64_t padding;
    };
    EventInfoList *next;
};

void qapi_free_EventInfoList(EventInfoList *obj);

struct FdsetFdInfo {
    int64_t fd;
    bool has_opaque;
    char *opaque;
};

void qapi_free_FdsetFdInfo(FdsetFdInfo *obj);

struct FdsetFdInfoList {
    union {
        FdsetFdInfo *value;
        uint64_t padding;
    };
    FdsetFdInfoList *next;
};

void qapi_free_FdsetFdInfoList(FdsetFdInfoList *obj);

struct FdsetInfo {
    int64_t fdset_id;
    FdsetFdInfoList *fds;
};

void qapi_free_FdsetInfo(FdsetInfo *obj);

struct FdsetInfoList {
    union {
        FdsetInfo *value;
        uint64_t padding;
    };
    FdsetInfoList *next;
};

void qapi_free_FdsetInfoList(FdsetInfoList *obj);

struct IOThreadInfo {
    char *id;
    int64_t thread_id;
};

void qapi_free_IOThreadInfo(IOThreadInfo *obj);

struct IOThreadInfoList {
    union {
        IOThreadInfo *value;
        uint64_t padding;
    };
    IOThreadInfoList *next;
};

void qapi_free_IOThreadInfoList(IOThreadInfoList *obj);

struct ImageCheck {
    char *filename;
    char *format;
    int64_t check_errors;
    bool has_image_end_offset;
    int64_t image_end_offset;
    bool has_corruptions;
    int64_t corruptions;
    bool has_leaks;
    int64_t leaks;
    bool has_corruptions_fixed;
    int64_t corruptions_fixed;
    bool has_leaks_fixed;
    int64_t leaks_fixed;
    bool has_total_clusters;
    int64_t total_clusters;
    bool has_allocated_clusters;
    int64_t allocated_clusters;
    bool has_fragmented_clusters;
    int64_t fragmented_clusters;
    bool has_compressed_clusters;
    int64_t compressed_clusters;
};

void qapi_free_ImageCheck(ImageCheck *obj);

struct ImageInfo {
    char *filename;
    char *format;
    bool has_dirty_flag;
    bool dirty_flag;
    bool has_actual_size;
    int64_t actual_size;
    int64_t virtual_size;
    bool has_cluster_size;
    int64_t cluster_size;
    bool has_encrypted;
    bool encrypted;
    bool has_compressed;
    bool compressed;
    bool has_backing_filename;
    char *backing_filename;
    bool has_full_backing_filename;
    char *full_backing_filename;
    bool has_backing_filename_format;
    char *backing_filename_format;
    bool has_snapshots;
    SnapshotInfoList *snapshots;
    bool has_backing_image;
    ImageInfo *backing_image;
    bool has_format_specific;
    ImageInfoSpecific *format_specific;
};

void qapi_free_ImageInfo(ImageInfo *obj);

struct ImageInfoList {
    union {
        ImageInfo *value;
        uint64_t padding;
    };
    ImageInfoList *next;
};

void qapi_free_ImageInfoList(ImageInfoList *obj);

struct ImageInfoSpecific {
    ImageInfoSpecificKind type;
    union { /* union tag is @type */
        void *data;
        ImageInfoSpecificQCow2 *qcow2;
        ImageInfoSpecificVmdk *vmdk;
    } u;
};

void qapi_free_ImageInfoSpecific(ImageInfoSpecific *obj);

struct ImageInfoSpecificQCow2 {
    char *compat;
    bool has_lazy_refcounts;
    bool lazy_refcounts;
    bool has_corrupt;
    bool corrupt;
    int64_t refcount_bits;
};

void qapi_free_ImageInfoSpecificQCow2(ImageInfoSpecificQCow2 *obj);

struct ImageInfoSpecificVmdk {
    char *create_type;
    int64_t cid;
    int64_t parent_cid;
    ImageInfoList *extents;
};

void qapi_free_ImageInfoSpecificVmdk(ImageInfoSpecificVmdk *obj);

struct InetSocketAddress {
    char *host;
    char *port;
    bool has_to;
    uint16_t to;
    bool has_ipv4;
    bool ipv4;
    bool has_ipv6;
    bool ipv6;
};

void qapi_free_InetSocketAddress(InetSocketAddress *obj);

struct InputBtnEvent {
    InputButton button;
    bool down;
};

void qapi_free_InputBtnEvent(InputBtnEvent *obj);

struct InputEvent {
    InputEventKind type;
    union { /* union tag is @type */
        void *data;
        InputKeyEvent *key;
        InputBtnEvent *btn;
        InputMoveEvent *rel;
        InputMoveEvent *abs;
    } u;
};

void qapi_free_InputEvent(InputEvent *obj);

struct InputEventList {
    union {
        InputEvent *value;
        uint64_t padding;
    };
    InputEventList *next;
};

void qapi_free_InputEventList(InputEventList *obj);

struct InputKeyEvent {
    KeyValue *key;
    bool down;
};

void qapi_free_InputKeyEvent(InputKeyEvent *obj);

struct InputMoveEvent {
    InputAxis axis;
    int64_t value;
};

void qapi_free_InputMoveEvent(InputMoveEvent *obj);

struct KeyValue {
    KeyValueKind type;
    union { /* union tag is @type */
        void *data;
        int64_t number;
        QKeyCode qcode;
    } u;
};

void qapi_free_KeyValue(KeyValue *obj);

struct KeyValueList {
    union {
        KeyValue *value;
        uint64_t padding;
    };
    KeyValueList *next;
};

void qapi_free_KeyValueList(KeyValueList *obj);

struct KvmInfo {
    bool enabled;
    bool present;
};

void qapi_free_KvmInfo(KvmInfo *obj);

struct MachineInfo {
    char *name;
    bool has_alias;
    char *alias;
    bool has_is_default;
    bool is_default;
    int64_t cpu_max;
};

void qapi_free_MachineInfo(MachineInfo *obj);

struct MachineInfoList {
    union {
        MachineInfo *value;
        uint64_t padding;
    };
    MachineInfoList *next;
};

void qapi_free_MachineInfoList(MachineInfoList *obj);

struct Memdev {
    uint64_t size;
    bool merge;
    bool dump;
    bool prealloc;
    uint16List *host_nodes;
    HostMemPolicy policy;
};

void qapi_free_Memdev(Memdev *obj);

struct MemdevList {
    union {
        Memdev *value;
        uint64_t padding;
    };
    MemdevList *next;
};

void qapi_free_MemdevList(MemdevList *obj);

struct MemoryDeviceInfo {
    MemoryDeviceInfoKind type;
    union { /* union tag is @type */
        void *data;
        PCDIMMDeviceInfo *dimm;
    } u;
};

void qapi_free_MemoryDeviceInfo(MemoryDeviceInfo *obj);

struct MemoryDeviceInfoList {
    union {
        MemoryDeviceInfo *value;
        uint64_t padding;
    };
    MemoryDeviceInfoList *next;
};

void qapi_free_MemoryDeviceInfoList(MemoryDeviceInfoList *obj);

struct MigrationCapabilityStatus {
    MigrationCapability capability;
    bool state;
};

void qapi_free_MigrationCapabilityStatus(MigrationCapabilityStatus *obj);

struct MigrationCapabilityStatusList {
    union {
        MigrationCapabilityStatus *value;
        uint64_t padding;
    };
    MigrationCapabilityStatusList *next;
};

void qapi_free_MigrationCapabilityStatusList(MigrationCapabilityStatusList *obj);

struct MigrationInfo {
    bool has_status;
    MigrationStatus status;
    bool has_ram;
    MigrationStats *ram;
    bool has_disk;
    MigrationStats *disk;
    bool has_xbzrle_cache;
    XBZRLECacheStats *xbzrle_cache;
    bool has_total_time;
    int64_t total_time;
    bool has_expected_downtime;
    int64_t expected_downtime;
    bool has_downtime;
    int64_t downtime;
    bool has_setup_time;
    int64_t setup_time;
    bool has_x_cpu_throttle_percentage;
    int64_t x_cpu_throttle_percentage;
};

void qapi_free_MigrationInfo(MigrationInfo *obj);

struct MigrationParameters {
    int64_t compress_level;
    int64_t compress_threads;
    int64_t decompress_threads;
    int64_t x_cpu_throttle_initial;
    int64_t x_cpu_throttle_increment;
};

void qapi_free_MigrationParameters(MigrationParameters *obj);

struct MigrationStats {
    int64_t transferred;
    int64_t remaining;
    int64_t total;
    int64_t duplicate;
    int64_t skipped;
    int64_t normal;
    int64_t normal_bytes;
    int64_t dirty_pages_rate;
    double mbps;
    int64_t dirty_sync_count;
};

void qapi_free_MigrationStats(MigrationStats *obj);

struct MouseInfo {
    char *name;
    int64_t index;
    bool current;
    bool absolute;
};

void qapi_free_MouseInfo(MouseInfo *obj);

struct MouseInfoList {
    union {
        MouseInfo *value;
        uint64_t padding;
    };
    MouseInfoList *next;
};

void qapi_free_MouseInfoList(MouseInfoList *obj);

struct NameInfo {
    bool has_name;
    char *name;
};

void qapi_free_NameInfo(NameInfo *obj);

struct NetClientOptions {
    NetClientOptionsKind type;
    union { /* union tag is @type */
        void *data;
        NetdevNoneOptions *none;
        NetLegacyNicOptions *nic;
        NetdevUserOptions *user;
        NetdevTapOptions *tap;
        NetdevL2TPv3Options *l2tpv3;
        NetdevSocketOptions *socket;
        NetdevVdeOptions *vde;
        NetdevDumpOptions *dump;
        NetdevBridgeOptions *bridge;
        NetdevHubPortOptions *hubport;
        NetdevNetmapOptions *netmap;
        NetdevVhostUserOptions *vhost_user;
    } u;
};

void qapi_free_NetClientOptions(NetClientOptions *obj);

struct NetLegacy {
    bool has_vlan;
    int32_t vlan;
    bool has_id;
    char *id;
    bool has_name;
    char *name;
    NetClientOptions *opts;
};

void qapi_free_NetLegacy(NetLegacy *obj);

struct NetLegacyNicOptions {
    bool has_netdev;
    char *netdev;
    bool has_macaddr;
    char *macaddr;
    bool has_model;
    char *model;
    bool has_addr;
    char *addr;
    bool has_vectors;
    uint32_t vectors;
};

void qapi_free_NetLegacyNicOptions(NetLegacyNicOptions *obj);

struct Netdev {
    char *id;
    NetClientOptions *opts;
};

void qapi_free_Netdev(Netdev *obj);

struct NetdevBridgeOptions {
    bool has_br;
    char *br;
    bool has_helper;
    char *helper;
};

void qapi_free_NetdevBridgeOptions(NetdevBridgeOptions *obj);

struct NetdevDumpOptions {
    bool has_len;
    uint64_t len;
    bool has_file;
    char *file;
};

void qapi_free_NetdevDumpOptions(NetdevDumpOptions *obj);

struct NetdevHubPortOptions {
    int32_t hubid;
};

void qapi_free_NetdevHubPortOptions(NetdevHubPortOptions *obj);

struct NetdevL2TPv3Options {
    char *src;
    char *dst;
    bool has_srcport;
    char *srcport;
    bool has_dstport;
    char *dstport;
    bool has_ipv6;
    bool ipv6;
    bool has_udp;
    bool udp;
    bool has_cookie64;
    bool cookie64;
    bool has_counter;
    bool counter;
    bool has_pincounter;
    bool pincounter;
    bool has_txcookie;
    uint64_t txcookie;
    bool has_rxcookie;
    uint64_t rxcookie;
    uint32_t txsession;
    bool has_rxsession;
    uint32_t rxsession;
    bool has_offset;
    uint32_t offset;
};

void qapi_free_NetdevL2TPv3Options(NetdevL2TPv3Options *obj);

struct NetdevNetmapOptions {
    char *ifname;
    bool has_devname;
    char *devname;
};

void qapi_free_NetdevNetmapOptions(NetdevNetmapOptions *obj);

struct NetdevNoneOptions {
    char qapi_dummy_field_for_empty_struct;
};

void qapi_free_NetdevNoneOptions(NetdevNoneOptions *obj);

struct NetdevSocketOptions {
    bool has_fd;
    char *fd;
    bool has_listen;
    char *listen;
    bool has_connect;
    char *connect;
    bool has_mcast;
    char *mcast;
    bool has_localaddr;
    char *localaddr;
    bool has_udp;
    char *udp;
};

void qapi_free_NetdevSocketOptions(NetdevSocketOptions *obj);

struct NetdevTapOptions {
    bool has_ifname;
    char *ifname;
    bool has_fd;
    char *fd;
    bool has_fds;
    char *fds;
    bool has_script;
    char *script;
    bool has_downscript;
    char *downscript;
    bool has_helper;
    char *helper;
    bool has_sndbuf;
    uint64_t sndbuf;
    bool has_vnet_hdr;
    bool vnet_hdr;
    bool has_vhost;
    bool vhost;
    bool has_vhostfd;
    char *vhostfd;
    bool has_vhostfds;
    char *vhostfds;
    bool has_vhostforce;
    bool vhostforce;
    bool has_queues;
    uint32_t queues;
};

void qapi_free_NetdevTapOptions(NetdevTapOptions *obj);

struct NetdevUserOptions {
    bool has_hostname;
    char *hostname;
    bool has_q_restrict;
    bool q_restrict;
    bool has_ip;
    char *ip;
    bool has_net;
    char *net;
    bool has_host;
    char *host;
    bool has_tftp;
    char *tftp;
    bool has_bootfile;
    char *bootfile;
    bool has_dhcpstart;
    char *dhcpstart;
    bool has_dns;
    char *dns;
    bool has_dnssearch;
    StringList *dnssearch;
    bool has_smb;
    char *smb;
    bool has_smbserver;
    char *smbserver;
    bool has_hostfwd;
    StringList *hostfwd;
    bool has_guestfwd;
    StringList *guestfwd;
};

void qapi_free_NetdevUserOptions(NetdevUserOptions *obj);

struct NetdevVdeOptions {
    bool has_sock;
    char *sock;
    bool has_port;
    uint16_t port;
    bool has_group;
    char *group;
    bool has_mode;
    uint16_t mode;
};

void qapi_free_NetdevVdeOptions(NetdevVdeOptions *obj);

struct NetdevVhostUserOptions {
    char *chardev;
    bool has_vhostforce;
    bool vhostforce;
    bool has_queues;
    int64_t queues;
};

void qapi_free_NetdevVhostUserOptions(NetdevVhostUserOptions *obj);

struct NumaNodeOptions {
    bool has_nodeid;
    uint16_t nodeid;
    bool has_cpus;
    uint16List *cpus;
    bool has_mem;
    uint64_t mem;
    bool has_memdev;
    char *memdev;
};

void qapi_free_NumaNodeOptions(NumaNodeOptions *obj);

struct NumaOptions {
    NumaOptionsKind type;
    union { /* union tag is @type */
        void *data;
        NumaNodeOptions *node;
    } u;
};

void qapi_free_NumaOptions(NumaOptions *obj);

struct ObjectPropertyInfo {
    char *name;
    char *type;
};

void qapi_free_ObjectPropertyInfo(ObjectPropertyInfo *obj);

struct ObjectPropertyInfoList {
    union {
        ObjectPropertyInfo *value;
        uint64_t padding;
    };
    ObjectPropertyInfoList *next;
};

void qapi_free_ObjectPropertyInfoList(ObjectPropertyInfoList *obj);

struct ObjectTypeInfo {
    char *name;
};

void qapi_free_ObjectTypeInfo(ObjectTypeInfo *obj);

struct ObjectTypeInfoList {
    union {
        ObjectTypeInfo *value;
        uint64_t padding;
    };
    ObjectTypeInfoList *next;
};

void qapi_free_ObjectTypeInfoList(ObjectTypeInfoList *obj);

struct PCDIMMDeviceInfo {
    bool has_id;
    char *id;
    int64_t addr;
    int64_t size;
    int64_t slot;
    int64_t node;
    char *memdev;
    bool hotplugged;
    bool hotpluggable;
};

void qapi_free_PCDIMMDeviceInfo(PCDIMMDeviceInfo *obj);

struct PciBridgeInfo {
    PciBusInfo *bus;
    bool has_devices;
    PciDeviceInfoList *devices;
};

void qapi_free_PciBridgeInfo(PciBridgeInfo *obj);

struct PciBusInfo {
    int64_t number;
    int64_t secondary;
    int64_t subordinate;
    PciMemoryRange *io_range;
    PciMemoryRange *memory_range;
    PciMemoryRange *prefetchable_range;
};

void qapi_free_PciBusInfo(PciBusInfo *obj);

struct PciDeviceClass {
    bool has_desc;
    char *desc;
    int64_t q_class;
};

void qapi_free_PciDeviceClass(PciDeviceClass *obj);

struct PciDeviceId {
    int64_t device;
    int64_t vendor;
};

void qapi_free_PciDeviceId(PciDeviceId *obj);

struct PciDeviceInfo {
    int64_t bus;
    int64_t slot;
    int64_t function;
    PciDeviceClass *class_info;
    PciDeviceId *id;
    bool has_irq;
    int64_t irq;
    char *qdev_id;
    bool has_pci_bridge;
    PciBridgeInfo *pci_bridge;
    PciMemoryRegionList *regions;
};

void qapi_free_PciDeviceInfo(PciDeviceInfo *obj);

struct PciDeviceInfoList {
    union {
        PciDeviceInfo *value;
        uint64_t padding;
    };
    PciDeviceInfoList *next;
};

void qapi_free_PciDeviceInfoList(PciDeviceInfoList *obj);

struct PciInfo {
    int64_t bus;
    PciDeviceInfoList *devices;
};

void qapi_free_PciInfo(PciInfo *obj);

struct PciInfoList {
    union {
        PciInfo *value;
        uint64_t padding;
    };
    PciInfoList *next;
};

void qapi_free_PciInfoList(PciInfoList *obj);

struct PciMemoryRange {
    int64_t base;
    int64_t limit;
};

void qapi_free_PciMemoryRange(PciMemoryRange *obj);

struct PciMemoryRegion {
    int64_t bar;
    char *type;
    int64_t address;
    int64_t size;
    bool has_prefetch;
    bool prefetch;
    bool has_mem_type_64;
    bool mem_type_64;
};

void qapi_free_PciMemoryRegion(PciMemoryRegion *obj);

struct PciMemoryRegionList {
    union {
        PciMemoryRegion *value;
        uint64_t padding;
    };
    PciMemoryRegionList *next;
};

void qapi_free_PciMemoryRegionList(PciMemoryRegionList *obj);

struct Qcow2OverlapCheckFlags {
    bool has_q_template;
    Qcow2OverlapCheckMode q_template;
    bool has_main_header;
    bool main_header;
    bool has_active_l1;
    bool active_l1;
    bool has_active_l2;
    bool active_l2;
    bool has_refcount_table;
    bool refcount_table;
    bool has_refcount_block;
    bool refcount_block;
    bool has_snapshot_table;
    bool snapshot_table;
    bool has_inactive_l1;
    bool inactive_l1;
    bool has_inactive_l2;
    bool inactive_l2;
};

void qapi_free_Qcow2OverlapCheckFlags(Qcow2OverlapCheckFlags *obj);

struct Qcow2OverlapChecks {
    Qcow2OverlapChecksKind type;
    union { /* union tag is @type */
        void *data;
        Qcow2OverlapCheckFlags *flags;
        Qcow2OverlapCheckMode mode;
    } u;
};

extern const int Qcow2OverlapChecks_qtypes[];

void qapi_free_Qcow2OverlapChecks(Qcow2OverlapChecks *obj);

struct RockerOfDpaFlow {
    uint64_t cookie;
    uint64_t hits;
    RockerOfDpaFlowKey *key;
    RockerOfDpaFlowMask *mask;
    RockerOfDpaFlowAction *action;
};

void qapi_free_RockerOfDpaFlow(RockerOfDpaFlow *obj);

struct RockerOfDpaFlowAction {
    bool has_goto_tbl;
    uint32_t goto_tbl;
    bool has_group_id;
    uint32_t group_id;
    bool has_tunnel_lport;
    uint32_t tunnel_lport;
    bool has_vlan_id;
    uint16_t vlan_id;
    bool has_new_vlan_id;
    uint16_t new_vlan_id;
    bool has_out_pport;
    uint32_t out_pport;
};

void qapi_free_RockerOfDpaFlowAction(RockerOfDpaFlowAction *obj);

struct RockerOfDpaFlowKey {
    uint32_t priority;
    uint32_t tbl_id;
    bool has_in_pport;
    uint32_t in_pport;
    bool has_tunnel_id;
    uint32_t tunnel_id;
    bool has_vlan_id;
    uint16_t vlan_id;
    bool has_eth_type;
    uint16_t eth_type;
    bool has_eth_src;
    char *eth_src;
    bool has_eth_dst;
    char *eth_dst;
    bool has_ip_proto;
    uint8_t ip_proto;
    bool has_ip_tos;
    uint8_t ip_tos;
    bool has_ip_dst;
    char *ip_dst;
};

void qapi_free_RockerOfDpaFlowKey(RockerOfDpaFlowKey *obj);

struct RockerOfDpaFlowList {
    union {
        RockerOfDpaFlow *value;
        uint64_t padding;
    };
    RockerOfDpaFlowList *next;
};

void qapi_free_RockerOfDpaFlowList(RockerOfDpaFlowList *obj);

struct RockerOfDpaFlowMask {
    bool has_in_pport;
    uint32_t in_pport;
    bool has_tunnel_id;
    uint32_t tunnel_id;
    bool has_vlan_id;
    uint16_t vlan_id;
    bool has_eth_src;
    char *eth_src;
    bool has_eth_dst;
    char *eth_dst;
    bool has_ip_proto;
    uint8_t ip_proto;
    bool has_ip_tos;
    uint8_t ip_tos;
};

void qapi_free_RockerOfDpaFlowMask(RockerOfDpaFlowMask *obj);

struct RockerOfDpaGroup {
    uint32_t id;
    uint8_t type;
    bool has_vlan_id;
    uint16_t vlan_id;
    bool has_pport;
    uint32_t pport;
    bool has_index;
    uint32_t index;
    bool has_out_pport;
    uint32_t out_pport;
    bool has_group_id;
    uint32_t group_id;
    bool has_set_vlan_id;
    uint16_t set_vlan_id;
    bool has_pop_vlan;
    uint8_t pop_vlan;
    bool has_group_ids;
    uint32List *group_ids;
    bool has_set_eth_src;
    char *set_eth_src;
    bool has_set_eth_dst;
    char *set_eth_dst;
    bool has_ttl_check;
    uint8_t ttl_check;
};

void qapi_free_RockerOfDpaGroup(RockerOfDpaGroup *obj);

struct RockerOfDpaGroupList {
    union {
        RockerOfDpaGroup *value;
        uint64_t padding;
    };
    RockerOfDpaGroupList *next;
};

void qapi_free_RockerOfDpaGroupList(RockerOfDpaGroupList *obj);

struct RockerPort {
    char *name;
    bool enabled;
    bool link_up;
    uint32_t speed;
    RockerPortDuplex duplex;
    RockerPortAutoneg autoneg;
};

void qapi_free_RockerPort(RockerPort *obj);

struct RockerPortList {
    union {
        RockerPort *value;
        uint64_t padding;
    };
    RockerPortList *next;
};

void qapi_free_RockerPortList(RockerPortList *obj);

struct RockerSwitch {
    char *name;
    uint64_t id;
    uint32_t ports;
};

void qapi_free_RockerSwitch(RockerSwitch *obj);

struct RxFilterInfo {
    char *name;
    bool promiscuous;
    RxState multicast;
    RxState unicast;
    RxState vlan;
    bool broadcast_allowed;
    bool multicast_overflow;
    bool unicast_overflow;
    char *main_mac;
    intList *vlan_table;
    strList *unicast_table;
    strList *multicast_table;
};

void qapi_free_RxFilterInfo(RxFilterInfo *obj);

struct RxFilterInfoList {
    union {
        RxFilterInfo *value;
        uint64_t padding;
    };
    RxFilterInfoList *next;
};

void qapi_free_RxFilterInfoList(RxFilterInfoList *obj);

struct SchemaInfo {
    /* Members inherited from SchemaInfoBase: */
    char *name;
    SchemaMetaType meta_type;
    /* Own members: */
    union { /* union tag is @meta_type */
        void *data;
        SchemaInfoBuiltin *builtin;
        SchemaInfoEnum *q_enum;
        SchemaInfoArray *array;
        SchemaInfoObject *object;
        SchemaInfoAlternate *alternate;
        SchemaInfoCommand *command;
        SchemaInfoEvent *event;
    } u;
};

static inline SchemaInfoBase *qapi_SchemaInfo_base(const SchemaInfo *obj)
{
    return (SchemaInfoBase *)obj;
}

void qapi_free_SchemaInfo(SchemaInfo *obj);

struct SchemaInfoAlternate {
    SchemaInfoAlternateMemberList *members;
};

void qapi_free_SchemaInfoAlternate(SchemaInfoAlternate *obj);

struct SchemaInfoAlternateMember {
    char *type;
};

void qapi_free_SchemaInfoAlternateMember(SchemaInfoAlternateMember *obj);

struct SchemaInfoAlternateMemberList {
    union {
        SchemaInfoAlternateMember *value;
        uint64_t padding;
    };
    SchemaInfoAlternateMemberList *next;
};

void qapi_free_SchemaInfoAlternateMemberList(SchemaInfoAlternateMemberList *obj);

struct SchemaInfoArray {
    char *element_type;
};

void qapi_free_SchemaInfoArray(SchemaInfoArray *obj);

struct SchemaInfoBase {
    char *name;
    SchemaMetaType meta_type;
};

void qapi_free_SchemaInfoBase(SchemaInfoBase *obj);

struct SchemaInfoBuiltin {
    JSONType json_type;
};

void qapi_free_SchemaInfoBuiltin(SchemaInfoBuiltin *obj);

struct SchemaInfoCommand {
    char *arg_type;
    char *ret_type;
};

void qapi_free_SchemaInfoCommand(SchemaInfoCommand *obj);

struct SchemaInfoEnum {
    strList *values;
};

void qapi_free_SchemaInfoEnum(SchemaInfoEnum *obj);

struct SchemaInfoEvent {
    char *arg_type;
};

void qapi_free_SchemaInfoEvent(SchemaInfoEvent *obj);

struct SchemaInfoList {
    union {
        SchemaInfo *value;
        uint64_t padding;
    };
    SchemaInfoList *next;
};

void qapi_free_SchemaInfoList(SchemaInfoList *obj);

struct SchemaInfoObject {
    SchemaInfoObjectMemberList *members;
    bool has_tag;
    char *tag;
    bool has_variants;
    SchemaInfoObjectVariantList *variants;
};

void qapi_free_SchemaInfoObject(SchemaInfoObject *obj);

struct SchemaInfoObjectMember {
    char *name;
    char *type;
    bool has_q_default;
    QObject *q_default;
};

void qapi_free_SchemaInfoObjectMember(SchemaInfoObjectMember *obj);

struct SchemaInfoObjectMemberList {
    union {
        SchemaInfoObjectMember *value;
        uint64_t padding;
    };
    SchemaInfoObjectMemberList *next;
};

void qapi_free_SchemaInfoObjectMemberList(SchemaInfoObjectMemberList *obj);

struct SchemaInfoObjectVariant {
    char *q_case;
    char *type;
};

void qapi_free_SchemaInfoObjectVariant(SchemaInfoObjectVariant *obj);

struct SchemaInfoObjectVariantList {
    union {
        SchemaInfoObjectVariant *value;
        uint64_t padding;
    };
    SchemaInfoObjectVariantList *next;
};

void qapi_free_SchemaInfoObjectVariantList(SchemaInfoObjectVariantList *obj);

struct SnapshotInfo {
    char *id;
    char *name;
    int64_t vm_state_size;
    int64_t date_sec;
    int64_t date_nsec;
    int64_t vm_clock_sec;
    int64_t vm_clock_nsec;
};

void qapi_free_SnapshotInfo(SnapshotInfo *obj);

struct SnapshotInfoList {
    union {
        SnapshotInfo *value;
        uint64_t padding;
    };
    SnapshotInfoList *next;
};

void qapi_free_SnapshotInfoList(SnapshotInfoList *obj);

struct SocketAddress {
    SocketAddressKind type;
    union { /* union tag is @type */
        void *data;
        InetSocketAddress *inet;
        UnixSocketAddress *q_unix;
        String *fd;
    } u;
};

void qapi_free_SocketAddress(SocketAddress *obj);

struct SpiceBasicInfo {
    char *host;
    char *port;
    NetworkAddressFamily family;
};

void qapi_free_SpiceBasicInfo(SpiceBasicInfo *obj);

struct SpiceChannel {
    /* Members inherited from SpiceBasicInfo: */
    char *host;
    char *port;
    NetworkAddressFamily family;
    /* Own members: */
    int64_t connection_id;
    int64_t channel_type;
    int64_t channel_id;
    bool tls;
};

static inline SpiceBasicInfo *qapi_SpiceChannel_base(const SpiceChannel *obj)
{
    return (SpiceBasicInfo *)obj;
}

void qapi_free_SpiceChannel(SpiceChannel *obj);

struct SpiceChannelList {
    union {
        SpiceChannel *value;
        uint64_t padding;
    };
    SpiceChannelList *next;
};

void qapi_free_SpiceChannelList(SpiceChannelList *obj);

struct SpiceInfo {
    bool enabled;
    bool migrated;
    bool has_host;
    char *host;
    bool has_port;
    int64_t port;
    bool has_tls_port;
    int64_t tls_port;
    bool has_auth;
    char *auth;
    bool has_compiled_version;
    char *compiled_version;
    SpiceQueryMouseMode mouse_mode;
    bool has_channels;
    SpiceChannelList *channels;
};

void qapi_free_SpiceInfo(SpiceInfo *obj);

struct SpiceServerInfo {
    /* Members inherited from SpiceBasicInfo: */
    char *host;
    char *port;
    NetworkAddressFamily family;
    /* Own members: */
    bool has_auth;
    char *auth;
};

static inline SpiceBasicInfo *qapi_SpiceServerInfo_base(const SpiceServerInfo *obj)
{
    return (SpiceBasicInfo *)obj;
}

void qapi_free_SpiceServerInfo(SpiceServerInfo *obj);

struct StatusInfo {
    bool running;
    bool singlestep;
    RunState status;
};

void qapi_free_StatusInfo(StatusInfo *obj);

struct String {
    char *str;
};

void qapi_free_String(String *obj);

struct StringList {
    union {
        String *value;
        uint64_t padding;
    };
    StringList *next;
};

void qapi_free_StringList(StringList *obj);

struct TPMInfo {
    char *id;
    TpmModel model;
    TpmTypeOptions *options;
};

void qapi_free_TPMInfo(TPMInfo *obj);

struct TPMInfoList {
    union {
        TPMInfo *value;
        uint64_t padding;
    };
    TPMInfoList *next;
};

void qapi_free_TPMInfoList(TPMInfoList *obj);

struct TPMPassthroughOptions {
    bool has_path;
    char *path;
    bool has_cancel_path;
    char *cancel_path;
};

void qapi_free_TPMPassthroughOptions(TPMPassthroughOptions *obj);

struct TargetInfo {
    char *arch;
};

void qapi_free_TargetInfo(TargetInfo *obj);

struct TpmModelList {
    union {
        TpmModel value;
        uint64_t padding;
    };
    TpmModelList *next;
};

void qapi_free_TpmModelList(TpmModelList *obj);

struct TpmTypeList {
    union {
        TpmType value;
        uint64_t padding;
    };
    TpmTypeList *next;
};

void qapi_free_TpmTypeList(TpmTypeList *obj);

struct TpmTypeOptions {
    TpmTypeOptionsKind type;
    union { /* union tag is @type */
        void *data;
        TPMPassthroughOptions *passthrough;
    } u;
};

void qapi_free_TpmTypeOptions(TpmTypeOptions *obj);

struct TraceEventInfo {
    char *name;
    TraceEventState state;
};

void qapi_free_TraceEventInfo(TraceEventInfo *obj);

struct TraceEventInfoList {
    union {
        TraceEventInfo *value;
        uint64_t padding;
    };
    TraceEventInfoList *next;
};

void qapi_free_TraceEventInfoList(TraceEventInfoList *obj);

struct TransactionAction {
    TransactionActionKind type;
    union { /* union tag is @type */
        void *data;
        BlockdevSnapshot *blockdev_snapshot;
        BlockdevSnapshotSync *blockdev_snapshot_sync;
        DriveBackup *drive_backup;
        BlockdevBackup *blockdev_backup;
        Abort *abort;
        BlockdevSnapshotInternal *blockdev_snapshot_internal_sync;
        BlockDirtyBitmapAdd *block_dirty_bitmap_add;
        BlockDirtyBitmap *block_dirty_bitmap_clear;
    } u;
};

void qapi_free_TransactionAction(TransactionAction *obj);

struct TransactionActionList {
    union {
        TransactionAction *value;
        uint64_t padding;
    };
    TransactionActionList *next;
};

void qapi_free_TransactionActionList(TransactionActionList *obj);

struct TransactionProperties {
    bool has_completion_mode;
    ActionCompletionMode completion_mode;
};

void qapi_free_TransactionProperties(TransactionProperties *obj);

struct UnixSocketAddress {
    char *path;
};

void qapi_free_UnixSocketAddress(UnixSocketAddress *obj);

struct UuidInfo {
    char *UUID;
};

void qapi_free_UuidInfo(UuidInfo *obj);

struct VersionInfo {
    VersionTriple *qemu;
    char *package;
};

void qapi_free_VersionInfo(VersionInfo *obj);

struct VersionTriple {
    int64_t major;
    int64_t minor;
    int64_t micro;
};

void qapi_free_VersionTriple(VersionTriple *obj);

struct VncBasicInfo {
    char *host;
    char *service;
    NetworkAddressFamily family;
    bool websocket;
};

void qapi_free_VncBasicInfo(VncBasicInfo *obj);

struct VncBasicInfoList {
    union {
        VncBasicInfo *value;
        uint64_t padding;
    };
    VncBasicInfoList *next;
};

void qapi_free_VncBasicInfoList(VncBasicInfoList *obj);

struct VncClientInfo {
    /* Members inherited from VncBasicInfo: */
    char *host;
    char *service;
    NetworkAddressFamily family;
    bool websocket;
    /* Own members: */
    bool has_x509_dname;
    char *x509_dname;
    bool has_sasl_username;
    char *sasl_username;
};

static inline VncBasicInfo *qapi_VncClientInfo_base(const VncClientInfo *obj)
{
    return (VncBasicInfo *)obj;
}

void qapi_free_VncClientInfo(VncClientInfo *obj);

struct VncClientInfoList {
    union {
        VncClientInfo *value;
        uint64_t padding;
    };
    VncClientInfoList *next;
};

void qapi_free_VncClientInfoList(VncClientInfoList *obj);

struct VncInfo {
    bool enabled;
    bool has_host;
    char *host;
    bool has_family;
    NetworkAddressFamily family;
    bool has_service;
    char *service;
    bool has_auth;
    char *auth;
    bool has_clients;
    VncClientInfoList *clients;
};

void qapi_free_VncInfo(VncInfo *obj);

struct VncInfo2 {
    char *id;
    VncBasicInfoList *server;
    VncClientInfoList *clients;
    VncPrimaryAuth auth;
    bool has_vencrypt;
    VncVencryptSubAuth vencrypt;
    bool has_display;
    char *display;
};

void qapi_free_VncInfo2(VncInfo2 *obj);

struct VncInfo2List {
    union {
        VncInfo2 *value;
        uint64_t padding;
    };
    VncInfo2List *next;
};

void qapi_free_VncInfo2List(VncInfo2List *obj);

struct VncServerInfo {
    /* Members inherited from VncBasicInfo: */
    char *host;
    char *service;
    NetworkAddressFamily family;
    bool websocket;
    /* Own members: */
    bool has_auth;
    char *auth;
};

static inline VncBasicInfo *qapi_VncServerInfo_base(const VncServerInfo *obj)
{
    return (VncBasicInfo *)obj;
}

void qapi_free_VncServerInfo(VncServerInfo *obj);

struct X86CPUFeatureWordInfo {
    int64_t cpuid_input_eax;
    bool has_cpuid_input_ecx;
    int64_t cpuid_input_ecx;
    X86CPURegister32 cpuid_register;
    int64_t features;
};

void qapi_free_X86CPUFeatureWordInfo(X86CPUFeatureWordInfo *obj);

struct X86CPUFeatureWordInfoList {
    union {
        X86CPUFeatureWordInfo *value;
        uint64_t padding;
    };
    X86CPUFeatureWordInfoList *next;
};

void qapi_free_X86CPUFeatureWordInfoList(X86CPUFeatureWordInfoList *obj);

struct XBZRLECacheStats {
    int64_t cache_size;
    int64_t bytes;
    int64_t pages;
    int64_t cache_miss;
    double cache_miss_rate;
    int64_t overflow;
};

void qapi_free_XBZRLECacheStats(XBZRLECacheStats *obj);

#endif

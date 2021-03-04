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

#ifndef TEST_QAPI_TYPES_H
#define TEST_QAPI_TYPES_H

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


typedef struct AltIntNum AltIntNum;

typedef enum AltIntNumKind {
    ALT_INT_NUM_KIND_I = 0,
    ALT_INT_NUM_KIND_N = 1,
    ALT_INT_NUM_KIND_MAX = 2,
} AltIntNumKind;

extern const char *const AltIntNumKind_lookup[];

typedef struct AltNumInt AltNumInt;

typedef enum AltNumIntKind {
    ALT_NUM_INT_KIND_N = 0,
    ALT_NUM_INT_KIND_I = 1,
    ALT_NUM_INT_KIND_MAX = 2,
} AltNumIntKind;

extern const char *const AltNumIntKind_lookup[];

typedef struct AltNumStr AltNumStr;

typedef enum AltNumStrKind {
    ALT_NUM_STR_KIND_N = 0,
    ALT_NUM_STR_KIND_S = 1,
    ALT_NUM_STR_KIND_MAX = 2,
} AltNumStrKind;

extern const char *const AltNumStrKind_lookup[];

typedef struct AltStrBool AltStrBool;

typedef enum AltStrBoolKind {
    ALT_STR_BOOL_KIND_S = 0,
    ALT_STR_BOOL_KIND_B = 1,
    ALT_STR_BOOL_KIND_MAX = 2,
} AltStrBoolKind;

extern const char *const AltStrBoolKind_lookup[];

typedef struct AltStrInt AltStrInt;

typedef enum AltStrIntKind {
    ALT_STR_INT_KIND_S = 0,
    ALT_STR_INT_KIND_I = 1,
    ALT_STR_INT_KIND_MAX = 2,
} AltStrIntKind;

extern const char *const AltStrIntKind_lookup[];

typedef struct AltStrNum AltStrNum;

typedef enum AltStrNumKind {
    ALT_STR_NUM_KIND_S = 0,
    ALT_STR_NUM_KIND_N = 1,
    ALT_STR_NUM_KIND_MAX = 2,
} AltStrNumKind;

extern const char *const AltStrNumKind_lookup[];

typedef struct Empty1 Empty1;

typedef struct Empty2 Empty2;

typedef enum EnumOne {
    ENUM_ONE_VALUE1 = 0,
    ENUM_ONE_VALUE2 = 1,
    ENUM_ONE_VALUE3 = 2,
    ENUM_ONE_MAX = 3,
} EnumOne;

extern const char *const EnumOne_lookup[];

typedef struct EventStructOne EventStructOne;

typedef struct ForceArrays ForceArrays;

typedef enum MyEnum {
    MY_ENUM_MAX = 0,
} MyEnum;

extern const char *const MyEnum_lookup[];

typedef struct NestedEnumsOne NestedEnumsOne;

typedef enum QEnumTwo {
    QENUM_TWO_VALUE1 = 0,
    QENUM_TWO_VALUE2 = 1,
    QENUM_TWO_MAX = 2,
} QEnumTwo;

extern const char *const QEnumTwo_lookup[];

typedef struct TestStruct TestStruct;

typedef struct TestStructList TestStructList;

typedef struct UserDefA UserDefA;

typedef struct UserDefAlternate UserDefAlternate;

typedef enum UserDefAlternateKind {
    USER_DEF_ALTERNATE_KIND_UDA = 0,
    USER_DEF_ALTERNATE_KIND_S = 1,
    USER_DEF_ALTERNATE_KIND_I = 2,
    USER_DEF_ALTERNATE_KIND_MAX = 3,
} UserDefAlternateKind;

extern const char *const UserDefAlternateKind_lookup[];

typedef struct UserDefB UserDefB;

typedef struct UserDefC UserDefC;

typedef struct UserDefFlatUnion UserDefFlatUnion;

typedef struct UserDefFlatUnion2 UserDefFlatUnion2;

typedef struct UserDefNativeListUnion UserDefNativeListUnion;

typedef enum UserDefNativeListUnionKind {
    USER_DEF_NATIVE_LIST_UNION_KIND_INTEGER = 0,
    USER_DEF_NATIVE_LIST_UNION_KIND_S8 = 1,
    USER_DEF_NATIVE_LIST_UNION_KIND_S16 = 2,
    USER_DEF_NATIVE_LIST_UNION_KIND_S32 = 3,
    USER_DEF_NATIVE_LIST_UNION_KIND_S64 = 4,
    USER_DEF_NATIVE_LIST_UNION_KIND_U8 = 5,
    USER_DEF_NATIVE_LIST_UNION_KIND_U16 = 6,
    USER_DEF_NATIVE_LIST_UNION_KIND_U32 = 7,
    USER_DEF_NATIVE_LIST_UNION_KIND_U64 = 8,
    USER_DEF_NATIVE_LIST_UNION_KIND_NUMBER = 9,
    USER_DEF_NATIVE_LIST_UNION_KIND_BOOLEAN = 10,
    USER_DEF_NATIVE_LIST_UNION_KIND_STRING = 11,
    USER_DEF_NATIVE_LIST_UNION_KIND_SIZES = 12,
    USER_DEF_NATIVE_LIST_UNION_KIND_ANY = 13,
    USER_DEF_NATIVE_LIST_UNION_KIND_MAX = 14,
} UserDefNativeListUnionKind;

extern const char *const UserDefNativeListUnionKind_lookup[];

typedef struct UserDefOne UserDefOne;

typedef struct UserDefOneList UserDefOneList;

typedef struct UserDefOptions UserDefOptions;

typedef struct UserDefTwo UserDefTwo;

typedef struct UserDefTwoDict UserDefTwoDict;

typedef struct UserDefTwoDictDict UserDefTwoDictDict;

typedef struct UserDefTwoList UserDefTwoList;

typedef struct UserDefUnionBase UserDefUnionBase;

typedef struct UserDefZero UserDefZero;

typedef struct __org_qemu_x_Alt __org_qemu_x_Alt;

typedef enum __org_qemu_x_AltKind {
    ORG_QEMU_X_ALT_KIND___ORG_QEMU_X_BRANCH = 0,
    ORG_QEMU_X_ALT_KIND_B = 1,
    ORG_QEMU_X_ALT_KIND_MAX = 2,
} __org_qemu_x_AltKind;

extern const char *const __org_qemu_x_AltKind_lookup[];

typedef struct __org_qemu_x_Base __org_qemu_x_Base;

typedef enum __org_qemu_x_Enum {
    ORG_QEMU_X_ENUM___ORG_QEMU_X_VALUE = 0,
    ORG_QEMU_X_ENUM_MAX = 1,
} __org_qemu_x_Enum;

extern const char *const __org_qemu_x_Enum_lookup[];

typedef struct __org_qemu_x_EnumList __org_qemu_x_EnumList;

typedef struct __org_qemu_x_Struct __org_qemu_x_Struct;

typedef struct __org_qemu_x_Struct2 __org_qemu_x_Struct2;

typedef struct __org_qemu_x_StructList __org_qemu_x_StructList;

typedef struct __org_qemu_x_Union1 __org_qemu_x_Union1;

typedef enum __org_qemu_x_Union1Kind {
    ORG_QEMU_X_UNION1_KIND___ORG_QEMU_X_BRANCH = 0,
    ORG_QEMU_X_UNION1_KIND_MAX = 1,
} __org_qemu_x_Union1Kind;

extern const char *const __org_qemu_x_Union1Kind_lookup[];

typedef struct __org_qemu_x_Union1List __org_qemu_x_Union1List;

typedef struct __org_qemu_x_Union2 __org_qemu_x_Union2;

struct AltIntNum {
    AltIntNumKind type;
    union { /* union tag is @type */
        void *data;
        int64_t i;
        double n;
    } u;
};

extern const int AltIntNum_qtypes[];

void qapi_free_AltIntNum(AltIntNum *obj);

struct AltNumInt {
    AltNumIntKind type;
    union { /* union tag is @type */
        void *data;
        double n;
        int64_t i;
    } u;
};

extern const int AltNumInt_qtypes[];

void qapi_free_AltNumInt(AltNumInt *obj);

struct AltNumStr {
    AltNumStrKind type;
    union { /* union tag is @type */
        void *data;
        double n;
        char *s;
    } u;
};

extern const int AltNumStr_qtypes[];

void qapi_free_AltNumStr(AltNumStr *obj);

struct AltStrBool {
    AltStrBoolKind type;
    union { /* union tag is @type */
        void *data;
        char *s;
        bool b;
    } u;
};

extern const int AltStrBool_qtypes[];

void qapi_free_AltStrBool(AltStrBool *obj);

struct AltStrInt {
    AltStrIntKind type;
    union { /* union tag is @type */
        void *data;
        char *s;
        int64_t i;
    } u;
};

extern const int AltStrInt_qtypes[];

void qapi_free_AltStrInt(AltStrInt *obj);

struct AltStrNum {
    AltStrNumKind type;
    union { /* union tag is @type */
        void *data;
        char *s;
        double n;
    } u;
};

extern const int AltStrNum_qtypes[];

void qapi_free_AltStrNum(AltStrNum *obj);

struct Empty1 {
    char qapi_dummy_field_for_empty_struct;
};

void qapi_free_Empty1(Empty1 *obj);

struct Empty2 {
    /* Members inherited from Empty1: */
    /* Own members: */
    char qapi_dummy_field_for_empty_struct;
};

static inline Empty1 *qapi_Empty2_base(const Empty2 *obj)
{
    return (Empty1 *)obj;
}

void qapi_free_Empty2(Empty2 *obj);

struct EventStructOne {
    UserDefOne *struct1;
    char *string;
    bool has_enum2;
    EnumOne enum2;
};

void qapi_free_EventStructOne(EventStructOne *obj);

struct ForceArrays {
    UserDefOneList *unused1;
    UserDefTwoList *unused2;
    TestStructList *unused3;
};

void qapi_free_ForceArrays(ForceArrays *obj);

struct NestedEnumsOne {
    EnumOne enum1;
    bool has_enum2;
    EnumOne enum2;
    EnumOne enum3;
    bool has_enum4;
    EnumOne enum4;
};

void qapi_free_NestedEnumsOne(NestedEnumsOne *obj);

struct TestStruct {
    int64_t integer;
    bool boolean;
    char *string;
};

void qapi_free_TestStruct(TestStruct *obj);

struct TestStructList {
    union {
        TestStruct *value;
        uint64_t padding;
    };
    TestStructList *next;
};

void qapi_free_TestStructList(TestStructList *obj);

struct UserDefA {
    bool boolean;
    bool has_a_b;
    int64_t a_b;
};

void qapi_free_UserDefA(UserDefA *obj);

struct UserDefAlternate {
    UserDefAlternateKind type;
    union { /* union tag is @type */
        void *data;
        UserDefA *uda;
        char *s;
        int64_t i;
    } u;
};

extern const int UserDefAlternate_qtypes[];

void qapi_free_UserDefAlternate(UserDefAlternate *obj);

struct UserDefB {
    int64_t intb;
    bool has_a_b;
    bool a_b;
};

void qapi_free_UserDefB(UserDefB *obj);

struct UserDefC {
    char *string1;
    char *string2;
};

void qapi_free_UserDefC(UserDefC *obj);

struct UserDefFlatUnion {
    /* Members inherited from UserDefUnionBase: */
    int64_t integer;
    char *string;
    EnumOne enum1;
    /* Own members: */
    union { /* union tag is @enum1 */
        void *data;
        UserDefA *value1;
        UserDefB *value2;
        UserDefB *value3;
    } u;
};

static inline UserDefUnionBase *qapi_UserDefFlatUnion_base(const UserDefFlatUnion *obj)
{
    return (UserDefUnionBase *)obj;
}

void qapi_free_UserDefFlatUnion(UserDefFlatUnion *obj);

struct UserDefFlatUnion2 {
    /* Members inherited from UserDefUnionBase: */
    int64_t integer;
    char *string;
    EnumOne enum1;
    /* Own members: */
    union { /* union tag is @enum1 */
        void *data;
        UserDefC *value1;
        UserDefB *value2;
        UserDefA *value3;
    } u;
};

static inline UserDefUnionBase *qapi_UserDefFlatUnion2_base(const UserDefFlatUnion2 *obj)
{
    return (UserDefUnionBase *)obj;
}

void qapi_free_UserDefFlatUnion2(UserDefFlatUnion2 *obj);

struct UserDefNativeListUnion {
    UserDefNativeListUnionKind type;
    union { /* union tag is @type */
        void *data;
        intList *integer;
        int8List *s8;
        int16List *s16;
        int32List *s32;
        int64List *s64;
        uint8List *u8;
        uint16List *u16;
        uint32List *u32;
        uint64List *u64;
        numberList *number;
        boolList *boolean;
        strList *string;
        sizeList *sizes;
        anyList *any;
    } u;
};

void qapi_free_UserDefNativeListUnion(UserDefNativeListUnion *obj);

struct UserDefOne {
    /* Members inherited from UserDefZero: */
    int64_t integer;
    /* Own members: */
    char *string;
    bool has_enum1;
    EnumOne enum1;
};

static inline UserDefZero *qapi_UserDefOne_base(const UserDefOne *obj)
{
    return (UserDefZero *)obj;
}

void qapi_free_UserDefOne(UserDefOne *obj);

struct UserDefOneList {
    union {
        UserDefOne *value;
        uint64_t padding;
    };
    UserDefOneList *next;
};

void qapi_free_UserDefOneList(UserDefOneList *obj);

struct UserDefOptions {
    bool has_i64;
    intList *i64;
    bool has_u64;
    uint64List *u64;
    bool has_u16;
    uint16List *u16;
    bool has_i64x;
    int64_t i64x;
    bool has_u64x;
    uint64_t u64x;
};

void qapi_free_UserDefOptions(UserDefOptions *obj);

struct UserDefTwo {
    char *string0;
    UserDefTwoDict *dict1;
};

void qapi_free_UserDefTwo(UserDefTwo *obj);

struct UserDefTwoDict {
    char *string1;
    UserDefTwoDictDict *dict2;
    bool has_dict3;
    UserDefTwoDictDict *dict3;
};

void qapi_free_UserDefTwoDict(UserDefTwoDict *obj);

struct UserDefTwoDictDict {
    UserDefOne *userdef;
    char *string;
};

void qapi_free_UserDefTwoDictDict(UserDefTwoDictDict *obj);

struct UserDefTwoList {
    union {
        UserDefTwo *value;
        uint64_t padding;
    };
    UserDefTwoList *next;
};

void qapi_free_UserDefTwoList(UserDefTwoList *obj);

struct UserDefUnionBase {
    /* Members inherited from UserDefZero: */
    int64_t integer;
    /* Own members: */
    char *string;
    EnumOne enum1;
};

static inline UserDefZero *qapi_UserDefUnionBase_base(const UserDefUnionBase *obj)
{
    return (UserDefZero *)obj;
}

void qapi_free_UserDefUnionBase(UserDefUnionBase *obj);

struct UserDefZero {
    int64_t integer;
};

void qapi_free_UserDefZero(UserDefZero *obj);

struct __org_qemu_x_Alt {
    __org_qemu_x_AltKind type;
    union { /* union tag is @type */
        void *data;
        char *__org_qemu_x_branch;
        __org_qemu_x_Base *b;
    } u;
};

extern const int __org_qemu_x_Alt_qtypes[];

void qapi_free___org_qemu_x_Alt(__org_qemu_x_Alt *obj);

struct __org_qemu_x_Base {
    __org_qemu_x_Enum __org_qemu_x_member1;
};

void qapi_free___org_qemu_x_Base(__org_qemu_x_Base *obj);

struct __org_qemu_x_EnumList {
    union {
        __org_qemu_x_Enum value;
        uint64_t padding;
    };
    __org_qemu_x_EnumList *next;
};

void qapi_free___org_qemu_x_EnumList(__org_qemu_x_EnumList *obj);

struct __org_qemu_x_Struct {
    /* Members inherited from __org_qemu_x_Base: */
    __org_qemu_x_Enum __org_qemu_x_member1;
    /* Own members: */
    char *__org_qemu_x_member2;
};

static inline __org_qemu_x_Base *qapi___org_qemu_x_Struct_base(const __org_qemu_x_Struct *obj)
{
    return (__org_qemu_x_Base *)obj;
}

void qapi_free___org_qemu_x_Struct(__org_qemu_x_Struct *obj);

struct __org_qemu_x_Struct2 {
    __org_qemu_x_Union1List *array;
};

void qapi_free___org_qemu_x_Struct2(__org_qemu_x_Struct2 *obj);

struct __org_qemu_x_StructList {
    union {
        __org_qemu_x_Struct *value;
        uint64_t padding;
    };
    __org_qemu_x_StructList *next;
};

void qapi_free___org_qemu_x_StructList(__org_qemu_x_StructList *obj);

struct __org_qemu_x_Union1 {
    __org_qemu_x_Union1Kind type;
    union { /* union tag is @type */
        void *data;
        char *__org_qemu_x_branch;
    } u;
};

void qapi_free___org_qemu_x_Union1(__org_qemu_x_Union1 *obj);

struct __org_qemu_x_Union1List {
    union {
        __org_qemu_x_Union1 *value;
        uint64_t padding;
    };
    __org_qemu_x_Union1List *next;
};

void qapi_free___org_qemu_x_Union1List(__org_qemu_x_Union1List *obj);

struct __org_qemu_x_Union2 {
    /* Members inherited from __org_qemu_x_Base: */
    __org_qemu_x_Enum __org_qemu_x_member1;
    /* Own members: */
    union { /* union tag is @__org_qemu_x_member1 */
        void *data;
        __org_qemu_x_Struct2 *__org_qemu_x_value;
    } u;
};

static inline __org_qemu_x_Base *qapi___org_qemu_x_Union2_base(const __org_qemu_x_Union2 *obj)
{
    return (__org_qemu_x_Base *)obj;
}

void qapi_free___org_qemu_x_Union2(__org_qemu_x_Union2 *obj);

#endif

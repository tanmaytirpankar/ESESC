/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI visitor functions
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

#ifndef TEST_QAPI_VISIT_H
#define TEST_QAPI_VISIT_H

#include "qapi/visitor.h"
#include "test-qapi-types.h"


#ifndef QAPI_VISIT_BUILTIN
#define QAPI_VISIT_BUILTIN

void visit_type_anyList(Visitor *v, anyList **obj, const char *name, Error **errp);
void visit_type_boolList(Visitor *v, boolList **obj, const char *name, Error **errp);
void visit_type_int16List(Visitor *v, int16List **obj, const char *name, Error **errp);
void visit_type_int32List(Visitor *v, int32List **obj, const char *name, Error **errp);
void visit_type_int64List(Visitor *v, int64List **obj, const char *name, Error **errp);
void visit_type_int8List(Visitor *v, int8List **obj, const char *name, Error **errp);
void visit_type_intList(Visitor *v, intList **obj, const char *name, Error **errp);
void visit_type_numberList(Visitor *v, numberList **obj, const char *name, Error **errp);
void visit_type_sizeList(Visitor *v, sizeList **obj, const char *name, Error **errp);
void visit_type_strList(Visitor *v, strList **obj, const char *name, Error **errp);
void visit_type_uint16List(Visitor *v, uint16List **obj, const char *name, Error **errp);
void visit_type_uint32List(Visitor *v, uint32List **obj, const char *name, Error **errp);
void visit_type_uint64List(Visitor *v, uint64List **obj, const char *name, Error **errp);
void visit_type_uint8List(Visitor *v, uint8List **obj, const char *name, Error **errp);

#endif /* QAPI_VISIT_BUILTIN */

void visit_type_AltIntNum(Visitor *v, AltIntNum **obj, const char *name, Error **errp);
void visit_type_AltIntNumKind(Visitor *v, AltIntNumKind *obj, const char *name, Error **errp);
void visit_type_AltNumInt(Visitor *v, AltNumInt **obj, const char *name, Error **errp);
void visit_type_AltNumIntKind(Visitor *v, AltNumIntKind *obj, const char *name, Error **errp);
void visit_type_AltNumStr(Visitor *v, AltNumStr **obj, const char *name, Error **errp);
void visit_type_AltNumStrKind(Visitor *v, AltNumStrKind *obj, const char *name, Error **errp);
void visit_type_AltStrBool(Visitor *v, AltStrBool **obj, const char *name, Error **errp);
void visit_type_AltStrBoolKind(Visitor *v, AltStrBoolKind *obj, const char *name, Error **errp);
void visit_type_AltStrInt(Visitor *v, AltStrInt **obj, const char *name, Error **errp);
void visit_type_AltStrIntKind(Visitor *v, AltStrIntKind *obj, const char *name, Error **errp);
void visit_type_AltStrNum(Visitor *v, AltStrNum **obj, const char *name, Error **errp);
void visit_type_AltStrNumKind(Visitor *v, AltStrNumKind *obj, const char *name, Error **errp);
void visit_type_Empty1(Visitor *v, Empty1 **obj, const char *name, Error **errp);
void visit_type_Empty2(Visitor *v, Empty2 **obj, const char *name, Error **errp);
void visit_type_EnumOne(Visitor *v, EnumOne *obj, const char *name, Error **errp);
void visit_type_EventStructOne(Visitor *v, EventStructOne **obj, const char *name, Error **errp);
void visit_type_ForceArrays(Visitor *v, ForceArrays **obj, const char *name, Error **errp);
void visit_type_MyEnum(Visitor *v, MyEnum *obj, const char *name, Error **errp);
void visit_type_NestedEnumsOne(Visitor *v, NestedEnumsOne **obj, const char *name, Error **errp);
void visit_type_QEnumTwo(Visitor *v, QEnumTwo *obj, const char *name, Error **errp);
void visit_type_TestStruct(Visitor *v, TestStruct **obj, const char *name, Error **errp);
void visit_type_TestStructList(Visitor *v, TestStructList **obj, const char *name, Error **errp);
void visit_type_UserDefA(Visitor *v, UserDefA **obj, const char *name, Error **errp);
void visit_type_UserDefAlternate(Visitor *v, UserDefAlternate **obj, const char *name, Error **errp);
void visit_type_UserDefAlternateKind(Visitor *v, UserDefAlternateKind *obj, const char *name, Error **errp);
void visit_type_UserDefB(Visitor *v, UserDefB **obj, const char *name, Error **errp);
void visit_type_UserDefC(Visitor *v, UserDefC **obj, const char *name, Error **errp);
void visit_type_UserDefFlatUnion(Visitor *v, UserDefFlatUnion **obj, const char *name, Error **errp);
void visit_type_UserDefFlatUnion2(Visitor *v, UserDefFlatUnion2 **obj, const char *name, Error **errp);
void visit_type_UserDefNativeListUnion(Visitor *v, UserDefNativeListUnion **obj, const char *name, Error **errp);
void visit_type_UserDefNativeListUnionKind(Visitor *v, UserDefNativeListUnionKind *obj, const char *name, Error **errp);
void visit_type_UserDefOne(Visitor *v, UserDefOne **obj, const char *name, Error **errp);
void visit_type_UserDefOneList(Visitor *v, UserDefOneList **obj, const char *name, Error **errp);
void visit_type_UserDefOptions(Visitor *v, UserDefOptions **obj, const char *name, Error **errp);
void visit_type_UserDefTwo(Visitor *v, UserDefTwo **obj, const char *name, Error **errp);
void visit_type_UserDefTwoDict(Visitor *v, UserDefTwoDict **obj, const char *name, Error **errp);
void visit_type_UserDefTwoDictDict(Visitor *v, UserDefTwoDictDict **obj, const char *name, Error **errp);
void visit_type_UserDefTwoList(Visitor *v, UserDefTwoList **obj, const char *name, Error **errp);
void visit_type_UserDefUnionBase(Visitor *v, UserDefUnionBase **obj, const char *name, Error **errp);
void visit_type_UserDefZero(Visitor *v, UserDefZero **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Alt(Visitor *v, __org_qemu_x_Alt **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_AltKind(Visitor *v, __org_qemu_x_AltKind *obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Base(Visitor *v, __org_qemu_x_Base **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Enum(Visitor *v, __org_qemu_x_Enum *obj, const char *name, Error **errp);
void visit_type___org_qemu_x_EnumList(Visitor *v, __org_qemu_x_EnumList **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Struct(Visitor *v, __org_qemu_x_Struct **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Struct2(Visitor *v, __org_qemu_x_Struct2 **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_StructList(Visitor *v, __org_qemu_x_StructList **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Union1(Visitor *v, __org_qemu_x_Union1 **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Union1Kind(Visitor *v, __org_qemu_x_Union1Kind *obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Union1List(Visitor *v, __org_qemu_x_Union1List **obj, const char *name, Error **errp);
void visit_type___org_qemu_x_Union2(Visitor *v, __org_qemu_x_Union2 **obj, const char *name, Error **errp);

#endif

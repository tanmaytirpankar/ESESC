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

#include "qemu-common.h"
#include "qapi-visit.h"

static void visit_type_ACPIOSTInfo_fields(Visitor *v, ACPIOSTInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_device, "device", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_device) {
        visit_type_str(v, &(*obj)->device, "device", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, &(*obj)->slot, "slot", &err);
    if (err) {
        goto out;
    }
    visit_type_ACPISlotType(v, &(*obj)->slot_type, "slot-type", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->source, "source", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->status, "status", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ACPIOSTInfo(Visitor *v, ACPIOSTInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ACPIOSTInfo", name, sizeof(ACPIOSTInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ACPIOSTInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ACPIOSTInfoList(Visitor *v, ACPIOSTInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ACPIOSTInfoList *native_i = (ACPIOSTInfoList *)i;
        visit_type_ACPIOSTInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_ACPISlotType(Visitor *v, ACPISlotType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ACPISlotType_lookup, "ACPISlotType", name, errp);
}

static void visit_type_Abort_fields(Visitor *v, Abort **obj, Error **errp)
{
    Error *err = NULL;

    error_propagate(errp, err);
}

void visit_type_Abort(Visitor *v, Abort **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "Abort", name, sizeof(Abort), &err);
    if (!err) {
        if (*obj) {
            visit_type_Abort_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_AcpiTableOptions_fields(Visitor *v, AcpiTableOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_sig, "sig", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_sig) {
        visit_type_str(v, &(*obj)->sig, "sig", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_rev, "rev", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rev) {
        visit_type_uint8(v, &(*obj)->rev, "rev", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_oem_id, "oem_id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_oem_id) {
        visit_type_str(v, &(*obj)->oem_id, "oem_id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_oem_table_id, "oem_table_id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_oem_table_id) {
        visit_type_str(v, &(*obj)->oem_table_id, "oem_table_id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_oem_rev, "oem_rev", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_oem_rev) {
        visit_type_uint32(v, &(*obj)->oem_rev, "oem_rev", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_asl_compiler_id, "asl_compiler_id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_asl_compiler_id) {
        visit_type_str(v, &(*obj)->asl_compiler_id, "asl_compiler_id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_asl_compiler_rev, "asl_compiler_rev", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_asl_compiler_rev) {
        visit_type_uint32(v, &(*obj)->asl_compiler_rev, "asl_compiler_rev", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_file, "file", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_file) {
        visit_type_str(v, &(*obj)->file, "file", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_data, "data", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_data) {
        visit_type_str(v, &(*obj)->data, "data", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_AcpiTableOptions(Visitor *v, AcpiTableOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "AcpiTableOptions", name, sizeof(AcpiTableOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_AcpiTableOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ActionCompletionMode(Visitor *v, ActionCompletionMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ActionCompletionMode_lookup, "ActionCompletionMode", name, errp);
}

static void visit_type_AddfdInfo_fields(Visitor *v, AddfdInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->fdset_id, "fdset-id", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->fd, "fd", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_AddfdInfo(Visitor *v, AddfdInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "AddfdInfo", name, sizeof(AddfdInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_AddfdInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BalloonInfo_fields(Visitor *v, BalloonInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->actual, "actual", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BalloonInfo(Visitor *v, BalloonInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BalloonInfo", name, sizeof(BalloonInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BalloonInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BiosAtaTranslation(Visitor *v, BiosAtaTranslation *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BiosAtaTranslation_lookup, "BiosAtaTranslation", name, errp);
}

void visit_type_BlkdebugEvent(Visitor *v, BlkdebugEvent *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlkdebugEvent_lookup, "BlkdebugEvent", name, errp);
}

static void visit_type_BlkdebugInjectErrorOptions_fields(Visitor *v, BlkdebugInjectErrorOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlkdebugEvent(v, &(*obj)->event, "event", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_state, "state", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_state) {
        visit_type_int(v, &(*obj)->state, "state", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_q_errno, "errno", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_q_errno) {
        visit_type_int(v, &(*obj)->q_errno, "errno", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_sector, "sector", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_sector) {
        visit_type_int(v, &(*obj)->sector, "sector", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_once, "once", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_once) {
        visit_type_bool(v, &(*obj)->once, "once", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_immediately, "immediately", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_immediately) {
        visit_type_bool(v, &(*obj)->immediately, "immediately", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlkdebugInjectErrorOptions(Visitor *v, BlkdebugInjectErrorOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlkdebugInjectErrorOptions", name, sizeof(BlkdebugInjectErrorOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlkdebugInjectErrorOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlkdebugInjectErrorOptionsList(Visitor *v, BlkdebugInjectErrorOptionsList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlkdebugInjectErrorOptionsList *native_i = (BlkdebugInjectErrorOptionsList *)i;
        visit_type_BlkdebugInjectErrorOptions(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlkdebugSetStateOptions_fields(Visitor *v, BlkdebugSetStateOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlkdebugEvent(v, &(*obj)->event, "event", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_state, "state", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_state) {
        visit_type_int(v, &(*obj)->state, "state", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->new_state, "new_state", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlkdebugSetStateOptions(Visitor *v, BlkdebugSetStateOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlkdebugSetStateOptions", name, sizeof(BlkdebugSetStateOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlkdebugSetStateOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlkdebugSetStateOptionsList(Visitor *v, BlkdebugSetStateOptionsList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlkdebugSetStateOptionsList *native_i = (BlkdebugSetStateOptionsList *)i;
        visit_type_BlkdebugSetStateOptions(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlockDeviceInfo_fields(Visitor *v, BlockDeviceInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->file, "file", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_node_name) {
        visit_type_str(v, &(*obj)->node_name, "node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_bool(v, &(*obj)->ro, "ro", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->drv, "drv", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_backing_file, "backing_file", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing_file) {
        visit_type_str(v, &(*obj)->backing_file, "backing_file", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->backing_file_depth, "backing_file_depth", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->encrypted, "encrypted", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->encryption_key_missing, "encryption_key_missing", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockdevDetectZeroesOptions(v, &(*obj)->detect_zeroes, "detect_zeroes", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->bps, "bps", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->bps_rd, "bps_rd", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->bps_wr, "bps_wr", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->iops, "iops", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->iops_rd, "iops_rd", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->iops_wr, "iops_wr", &err);
    if (err) {
        goto out;
    }
    visit_type_ImageInfo(v, &(*obj)->image, "image", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_bps_max, "bps_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_bps_max) {
        visit_type_int(v, &(*obj)->bps_max, "bps_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_bps_rd_max, "bps_rd_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_bps_rd_max) {
        visit_type_int(v, &(*obj)->bps_rd_max, "bps_rd_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_bps_wr_max, "bps_wr_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_bps_wr_max) {
        visit_type_int(v, &(*obj)->bps_wr_max, "bps_wr_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_iops_max, "iops_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_iops_max) {
        visit_type_int(v, &(*obj)->iops_max, "iops_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_iops_rd_max, "iops_rd_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_iops_rd_max) {
        visit_type_int(v, &(*obj)->iops_rd_max, "iops_rd_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_iops_wr_max, "iops_wr_max", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_iops_wr_max) {
        visit_type_int(v, &(*obj)->iops_wr_max, "iops_wr_max", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_iops_size, "iops_size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_iops_size) {
        visit_type_int(v, &(*obj)->iops_size, "iops_size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_group, "group", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_group) {
        visit_type_str(v, &(*obj)->group, "group", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_BlockdevCacheInfo(v, &(*obj)->cache, "cache", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->write_threshold, "write_threshold", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDeviceInfo(Visitor *v, BlockDeviceInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDeviceInfo", name, sizeof(BlockDeviceInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDeviceInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockDeviceInfoList(Visitor *v, BlockDeviceInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockDeviceInfoList *native_i = (BlockDeviceInfoList *)i;
        visit_type_BlockDeviceInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_BlockDeviceIoStatus(Visitor *v, BlockDeviceIoStatus *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockDeviceIoStatus_lookup, "BlockDeviceIoStatus", name, errp);
}

static void visit_type_BlockDeviceMapEntry_fields(Visitor *v, BlockDeviceMapEntry **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->start, "start", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->length, "length", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->depth, "depth", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->zero, "zero", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->data, "data", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_offset, "offset", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_offset) {
        visit_type_int(v, &(*obj)->offset, "offset", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDeviceMapEntry(Visitor *v, BlockDeviceMapEntry **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDeviceMapEntry", name, sizeof(BlockDeviceMapEntry), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDeviceMapEntry_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockDeviceStats_fields(Visitor *v, BlockDeviceStats **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->rd_bytes, "rd_bytes", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->wr_bytes, "wr_bytes", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->rd_operations, "rd_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->wr_operations, "wr_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->flush_operations, "flush_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->flush_total_time_ns, "flush_total_time_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->wr_total_time_ns, "wr_total_time_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->rd_total_time_ns, "rd_total_time_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->wr_highest_offset, "wr_highest_offset", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->rd_merged, "rd_merged", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->wr_merged, "wr_merged", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_idle_time_ns, "idle_time_ns", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_idle_time_ns) {
        visit_type_int(v, &(*obj)->idle_time_ns, "idle_time_ns", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->failed_rd_operations, "failed_rd_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->failed_wr_operations, "failed_wr_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->failed_flush_operations, "failed_flush_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->invalid_rd_operations, "invalid_rd_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->invalid_wr_operations, "invalid_wr_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->invalid_flush_operations, "invalid_flush_operations", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->account_invalid, "account_invalid", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->account_failed, "account_failed", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockDeviceTimedStatsList(v, &(*obj)->timed_stats, "timed_stats", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDeviceStats(Visitor *v, BlockDeviceStats **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDeviceStats", name, sizeof(BlockDeviceStats), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDeviceStats_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockDeviceTimedStats_fields(Visitor *v, BlockDeviceTimedStats **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->interval_length, "interval_length", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->min_rd_latency_ns, "min_rd_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->max_rd_latency_ns, "max_rd_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->avg_rd_latency_ns, "avg_rd_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->min_wr_latency_ns, "min_wr_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->max_wr_latency_ns, "max_wr_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->avg_wr_latency_ns, "avg_wr_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->min_flush_latency_ns, "min_flush_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->max_flush_latency_ns, "max_flush_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->avg_flush_latency_ns, "avg_flush_latency_ns", &err);
    if (err) {
        goto out;
    }
    visit_type_number(v, &(*obj)->avg_rd_queue_depth, "avg_rd_queue_depth", &err);
    if (err) {
        goto out;
    }
    visit_type_number(v, &(*obj)->avg_wr_queue_depth, "avg_wr_queue_depth", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDeviceTimedStats(Visitor *v, BlockDeviceTimedStats **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDeviceTimedStats", name, sizeof(BlockDeviceTimedStats), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDeviceTimedStats_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockDeviceTimedStatsList(Visitor *v, BlockDeviceTimedStatsList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockDeviceTimedStatsList *native_i = (BlockDeviceTimedStatsList *)i;
        visit_type_BlockDeviceTimedStats(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlockDirtyBitmap_fields(Visitor *v, BlockDirtyBitmap **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->node, "node", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDirtyBitmap(Visitor *v, BlockDirtyBitmap **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDirtyBitmap", name, sizeof(BlockDirtyBitmap), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDirtyBitmap_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockDirtyBitmapAdd_fields(Visitor *v, BlockDirtyBitmapAdd **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->node, "node", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_granularity, "granularity", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_granularity) {
        visit_type_uint32(v, &(*obj)->granularity, "granularity", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDirtyBitmapAdd(Visitor *v, BlockDirtyBitmapAdd **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDirtyBitmapAdd", name, sizeof(BlockDirtyBitmapAdd), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDirtyBitmapAdd_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockDirtyInfo_fields(Visitor *v, BlockDirtyInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_name, "name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_name) {
        visit_type_str(v, &(*obj)->name, "name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->count, "count", &err);
    if (err) {
        goto out;
    }
    visit_type_uint32(v, &(*obj)->granularity, "granularity", &err);
    if (err) {
        goto out;
    }
    visit_type_DirtyBitmapStatus(v, &(*obj)->status, "status", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockDirtyInfo(Visitor *v, BlockDirtyInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockDirtyInfo", name, sizeof(BlockDirtyInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockDirtyInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockDirtyInfoList(Visitor *v, BlockDirtyInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockDirtyInfoList *native_i = (BlockDirtyInfoList *)i;
        visit_type_BlockDirtyInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_BlockErrorAction(Visitor *v, BlockErrorAction *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockErrorAction_lookup, "BlockErrorAction", name, errp);
}

static void visit_type_BlockInfo_fields(Visitor *v, BlockInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->removable, "removable", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->locked, "locked", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_inserted, "inserted", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_inserted) {
        visit_type_BlockDeviceInfo(v, &(*obj)->inserted, "inserted", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tray_open, "tray_open", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tray_open) {
        visit_type_bool(v, &(*obj)->tray_open, "tray_open", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_io_status, "io-status", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_io_status) {
        visit_type_BlockDeviceIoStatus(v, &(*obj)->io_status, "io-status", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_dirty_bitmaps, "dirty-bitmaps", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dirty_bitmaps) {
        visit_type_BlockDirtyInfoList(v, &(*obj)->dirty_bitmaps, "dirty-bitmaps", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockInfo(Visitor *v, BlockInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockInfo", name, sizeof(BlockInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockInfoList(Visitor *v, BlockInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockInfoList *native_i = (BlockInfoList *)i;
        visit_type_BlockInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlockJobInfo_fields(Visitor *v, BlockJobInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->len, "len", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->offset, "offset", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->busy, "busy", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->paused, "paused", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->speed, "speed", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockDeviceIoStatus(v, &(*obj)->io_status, "io-status", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->ready, "ready", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockJobInfo(Visitor *v, BlockJobInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockJobInfo", name, sizeof(BlockJobInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockJobInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockJobInfoList(Visitor *v, BlockJobInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockJobInfoList *native_i = (BlockJobInfoList *)i;
        visit_type_BlockJobInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_BlockJobType(Visitor *v, BlockJobType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockJobType_lookup, "BlockJobType", name, errp);
}

static void visit_type_BlockStats_fields(Visitor *v, BlockStats **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_device, "device", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_device) {
        visit_type_str(v, &(*obj)->device, "device", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_node_name) {
        visit_type_str(v, &(*obj)->node_name, "node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_BlockDeviceStats(v, &(*obj)->stats, "stats", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_parent, "parent", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_parent) {
        visit_type_BlockStats(v, &(*obj)->parent, "parent", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_backing, "backing", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing) {
        visit_type_BlockStats(v, &(*obj)->backing, "backing", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockStats(Visitor *v, BlockStats **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockStats", name, sizeof(BlockStats), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockStats_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockStatsList(Visitor *v, BlockStatsList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockStatsList *native_i = (BlockStatsList *)i;
        visit_type_BlockStats(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_BlockdevAioOptions(Visitor *v, BlockdevAioOptions *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevAioOptions_lookup, "BlockdevAioOptions", name, errp);
}

static void visit_type_BlockdevBackup_fields(Visitor *v, BlockdevBackup **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->target, "target", &err);
    if (err) {
        goto out;
    }
    visit_type_MirrorSyncMode(v, &(*obj)->sync, "sync", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_speed, "speed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_speed) {
        visit_type_int(v, &(*obj)->speed, "speed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_on_source_error, "on-source-error", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_on_source_error) {
        visit_type_BlockdevOnError(v, &(*obj)->on_source_error, "on-source-error", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_on_target_error, "on-target-error", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_on_target_error) {
        visit_type_BlockdevOnError(v, &(*obj)->on_target_error, "on-target-error", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevBackup(Visitor *v, BlockdevBackup **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevBackup", name, sizeof(BlockdevBackup), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevBackup_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevCacheInfo_fields(Visitor *v, BlockdevCacheInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, &(*obj)->writeback, "writeback", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->direct, "direct", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->no_flush, "no-flush", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevCacheInfo(Visitor *v, BlockdevCacheInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevCacheInfo", name, sizeof(BlockdevCacheInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevCacheInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevCacheOptions_fields(Visitor *v, BlockdevCacheOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_writeback, "writeback", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_writeback) {
        visit_type_bool(v, &(*obj)->writeback, "writeback", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_direct, "direct", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_direct) {
        visit_type_bool(v, &(*obj)->direct, "direct", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_no_flush, "no-flush", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_no_flush) {
        visit_type_bool(v, &(*obj)->no_flush, "no-flush", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevCacheOptions(Visitor *v, BlockdevCacheOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevCacheOptions", name, sizeof(BlockdevCacheOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevCacheOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockdevChangeReadOnlyMode(Visitor *v, BlockdevChangeReadOnlyMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevChangeReadOnlyMode_lookup, "BlockdevChangeReadOnlyMode", name, errp);
}

void visit_type_BlockdevDetectZeroesOptions(Visitor *v, BlockdevDetectZeroesOptions *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevDetectZeroesOptions_lookup, "BlockdevDetectZeroesOptions", name, errp);
}

void visit_type_BlockdevDiscardOptions(Visitor *v, BlockdevDiscardOptions *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevDiscardOptions_lookup, "BlockdevDiscardOptions", name, errp);
}

void visit_type_BlockdevDriver(Visitor *v, BlockdevDriver *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevDriver_lookup, "BlockdevDriver", name, errp);
}

void visit_type_BlockdevOnError(Visitor *v, BlockdevOnError *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevOnError_lookup, "BlockdevOnError", name, errp);
}

static void visit_type_BlockdevOptionsBase_fields(Visitor *v, BlockdevOptionsBase **obj, Error **errp);

static void visit_type_BlockdevOptionsArchipelago_fields(Visitor *v, BlockdevOptionsArchipelago **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsArchipelago(Visitor *v, BlockdevOptionsArchipelago **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsArchipelago), &err);
    if (!err) {
        visit_type_BlockdevOptionsArchipelago_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsBlkdebug_fields(Visitor *v, BlockdevOptionsBlkdebug **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsBlkdebug(Visitor *v, BlockdevOptionsBlkdebug **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsBlkdebug), &err);
    if (!err) {
        visit_type_BlockdevOptionsBlkdebug_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsBlkverify_fields(Visitor *v, BlockdevOptionsBlkverify **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsBlkverify(Visitor *v, BlockdevOptionsBlkverify **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsBlkverify), &err);
    if (!err) {
        visit_type_BlockdevOptionsBlkverify_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsGenericFormat_fields(Visitor *v, BlockdevOptionsGenericFormat **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsGenericFormat(Visitor *v, BlockdevOptionsGenericFormat **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsGenericFormat), &err);
    if (!err) {
        visit_type_BlockdevOptionsGenericFormat_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsFile_fields(Visitor *v, BlockdevOptionsFile **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsFile(Visitor *v, BlockdevOptionsFile **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsFile), &err);
    if (!err) {
        visit_type_BlockdevOptionsFile_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsNull_fields(Visitor *v, BlockdevOptionsNull **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsNull(Visitor *v, BlockdevOptionsNull **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsNull), &err);
    if (!err) {
        visit_type_BlockdevOptionsNull_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsQcow2_fields(Visitor *v, BlockdevOptionsQcow2 **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsQcow2(Visitor *v, BlockdevOptionsQcow2 **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsQcow2), &err);
    if (!err) {
        visit_type_BlockdevOptionsQcow2_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsGenericCOWFormat_fields(Visitor *v, BlockdevOptionsGenericCOWFormat **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsGenericCOWFormat(Visitor *v, BlockdevOptionsGenericCOWFormat **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsGenericCOWFormat), &err);
    if (!err) {
        visit_type_BlockdevOptionsGenericCOWFormat_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsQuorum_fields(Visitor *v, BlockdevOptionsQuorum **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsQuorum(Visitor *v, BlockdevOptionsQuorum **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsQuorum), &err);
    if (!err) {
        visit_type_BlockdevOptionsQuorum_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsVVFAT_fields(Visitor *v, BlockdevOptionsVVFAT **obj, Error **errp);

static void visit_type_implicit_BlockdevOptionsVVFAT(Visitor *v, BlockdevOptionsVVFAT **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(BlockdevOptionsVVFAT), &err);
    if (!err) {
        visit_type_BlockdevOptionsVVFAT_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockdevOptions(Visitor *v, BlockdevOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptions", name, sizeof(BlockdevOptions), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_BlockdevOptionsBase_fields(v, (BlockdevOptionsBase **)obj, &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->driver) {
    case BLOCKDEV_DRIVER_ARCHIPELAGO:
        visit_type_implicit_BlockdevOptionsArchipelago(v, &(*obj)->u.archipelago, &err);
        break;
    case BLOCKDEV_DRIVER_BLKDEBUG:
        visit_type_implicit_BlockdevOptionsBlkdebug(v, &(*obj)->u.blkdebug, &err);
        break;
    case BLOCKDEV_DRIVER_BLKVERIFY:
        visit_type_implicit_BlockdevOptionsBlkverify(v, &(*obj)->u.blkverify, &err);
        break;
    case BLOCKDEV_DRIVER_BOCHS:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.bochs, &err);
        break;
    case BLOCKDEV_DRIVER_CLOOP:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.cloop, &err);
        break;
    case BLOCKDEV_DRIVER_DMG:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.dmg, &err);
        break;
    case BLOCKDEV_DRIVER_FILE:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.file, &err);
        break;
    case BLOCKDEV_DRIVER_FTP:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.ftp, &err);
        break;
    case BLOCKDEV_DRIVER_FTPS:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.ftps, &err);
        break;
    case BLOCKDEV_DRIVER_HOST_CDROM:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.host_cdrom, &err);
        break;
    case BLOCKDEV_DRIVER_HOST_DEVICE:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.host_device, &err);
        break;
    case BLOCKDEV_DRIVER_HTTP:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.http, &err);
        break;
    case BLOCKDEV_DRIVER_HTTPS:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.https, &err);
        break;
    case BLOCKDEV_DRIVER_NULL_AIO:
        visit_type_implicit_BlockdevOptionsNull(v, &(*obj)->u.null_aio, &err);
        break;
    case BLOCKDEV_DRIVER_NULL_CO:
        visit_type_implicit_BlockdevOptionsNull(v, &(*obj)->u.null_co, &err);
        break;
    case BLOCKDEV_DRIVER_PARALLELS:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.parallels, &err);
        break;
    case BLOCKDEV_DRIVER_QCOW2:
        visit_type_implicit_BlockdevOptionsQcow2(v, &(*obj)->u.qcow2, &err);
        break;
    case BLOCKDEV_DRIVER_QCOW:
        visit_type_implicit_BlockdevOptionsGenericCOWFormat(v, &(*obj)->u.qcow, &err);
        break;
    case BLOCKDEV_DRIVER_QED:
        visit_type_implicit_BlockdevOptionsGenericCOWFormat(v, &(*obj)->u.qed, &err);
        break;
    case BLOCKDEV_DRIVER_QUORUM:
        visit_type_implicit_BlockdevOptionsQuorum(v, &(*obj)->u.quorum, &err);
        break;
    case BLOCKDEV_DRIVER_RAW:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.raw, &err);
        break;
    case BLOCKDEV_DRIVER_TFTP:
        visit_type_implicit_BlockdevOptionsFile(v, &(*obj)->u.tftp, &err);
        break;
    case BLOCKDEV_DRIVER_VDI:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.vdi, &err);
        break;
    case BLOCKDEV_DRIVER_VHDX:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.vhdx, &err);
        break;
    case BLOCKDEV_DRIVER_VMDK:
        visit_type_implicit_BlockdevOptionsGenericCOWFormat(v, &(*obj)->u.vmdk, &err);
        break;
    case BLOCKDEV_DRIVER_VPC:
        visit_type_implicit_BlockdevOptionsGenericFormat(v, &(*obj)->u.vpc, &err);
        break;
    case BLOCKDEV_DRIVER_VVFAT:
        visit_type_implicit_BlockdevOptionsVVFAT(v, &(*obj)->u.vvfat, &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsArchipelago_fields(Visitor *v, BlockdevOptionsArchipelago **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->volume, "volume", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_mport, "mport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mport) {
        visit_type_int(v, &(*obj)->mport, "mport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vport, "vport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vport) {
        visit_type_int(v, &(*obj)->vport, "vport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_segment, "segment", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_segment) {
        visit_type_str(v, &(*obj)->segment, "segment", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsArchipelago(Visitor *v, BlockdevOptionsArchipelago **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsArchipelago", name, sizeof(BlockdevOptionsArchipelago), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsArchipelago_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsBase_fields(Visitor *v, BlockdevOptionsBase **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevDriver(v, &(*obj)->driver, "driver", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_id, "id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_id) {
        visit_type_str(v, &(*obj)->id, "id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_node_name) {
        visit_type_str(v, &(*obj)->node_name, "node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_discard, "discard", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_discard) {
        visit_type_BlockdevDiscardOptions(v, &(*obj)->discard, "discard", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cache, "cache", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cache) {
        visit_type_BlockdevCacheOptions(v, &(*obj)->cache, "cache", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_aio, "aio", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_aio) {
        visit_type_BlockdevAioOptions(v, &(*obj)->aio, "aio", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_rerror, "rerror", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rerror) {
        visit_type_BlockdevOnError(v, &(*obj)->rerror, "rerror", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_werror, "werror", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_werror) {
        visit_type_BlockdevOnError(v, &(*obj)->werror, "werror", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_read_only, "read-only", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_read_only) {
        visit_type_bool(v, &(*obj)->read_only, "read-only", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_stats_account_invalid, "stats-account-invalid", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_stats_account_invalid) {
        visit_type_bool(v, &(*obj)->stats_account_invalid, "stats-account-invalid", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_stats_account_failed, "stats-account-failed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_stats_account_failed) {
        visit_type_bool(v, &(*obj)->stats_account_failed, "stats-account-failed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_stats_intervals, "stats-intervals", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_stats_intervals) {
        visit_type_intList(v, &(*obj)->stats_intervals, "stats-intervals", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_detect_zeroes, "detect-zeroes", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_detect_zeroes) {
        visit_type_BlockdevDetectZeroesOptions(v, &(*obj)->detect_zeroes, "detect-zeroes", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsBase(Visitor *v, BlockdevOptionsBase **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsBase", name, sizeof(BlockdevOptionsBase), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsBase_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsBlkdebug_fields(Visitor *v, BlockdevOptionsBlkdebug **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevRef(v, &(*obj)->image, "image", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_config, "config", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_config) {
        visit_type_str(v, &(*obj)->config, "config", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_align, "align", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_align) {
        visit_type_int(v, &(*obj)->align, "align", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_inject_error, "inject-error", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_inject_error) {
        visit_type_BlkdebugInjectErrorOptionsList(v, &(*obj)->inject_error, "inject-error", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_set_state, "set-state", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_set_state) {
        visit_type_BlkdebugSetStateOptionsList(v, &(*obj)->set_state, "set-state", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsBlkdebug(Visitor *v, BlockdevOptionsBlkdebug **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsBlkdebug", name, sizeof(BlockdevOptionsBlkdebug), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsBlkdebug_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsBlkverify_fields(Visitor *v, BlockdevOptionsBlkverify **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevRef(v, &(*obj)->test, "test", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockdevRef(v, &(*obj)->raw, "raw", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsBlkverify(Visitor *v, BlockdevOptionsBlkverify **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsBlkverify", name, sizeof(BlockdevOptionsBlkverify), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsBlkverify_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsFile_fields(Visitor *v, BlockdevOptionsFile **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->filename, "filename", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsFile(Visitor *v, BlockdevOptionsFile **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsFile", name, sizeof(BlockdevOptionsFile), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsFile_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsGenericCOWFormat_fields(Visitor *v, BlockdevOptionsGenericCOWFormat **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevOptionsGenericFormat_fields(v, (BlockdevOptionsGenericFormat **)obj, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_backing, "backing", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing) {
        visit_type_BlockdevRef(v, &(*obj)->backing, "backing", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsGenericCOWFormat(Visitor *v, BlockdevOptionsGenericCOWFormat **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsGenericCOWFormat", name, sizeof(BlockdevOptionsGenericCOWFormat), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsGenericCOWFormat_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsGenericFormat_fields(Visitor *v, BlockdevOptionsGenericFormat **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevRef(v, &(*obj)->file, "file", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsGenericFormat(Visitor *v, BlockdevOptionsGenericFormat **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsGenericFormat", name, sizeof(BlockdevOptionsGenericFormat), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsGenericFormat_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsNull_fields(Visitor *v, BlockdevOptionsNull **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_size, "size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_size) {
        visit_type_int(v, &(*obj)->size, "size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_latency_ns, "latency-ns", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_latency_ns) {
        visit_type_uint64(v, &(*obj)->latency_ns, "latency-ns", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsNull(Visitor *v, BlockdevOptionsNull **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsNull", name, sizeof(BlockdevOptionsNull), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsNull_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsQcow2_fields(Visitor *v, BlockdevOptionsQcow2 **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_BlockdevOptionsGenericCOWFormat_fields(v, (BlockdevOptionsGenericCOWFormat **)obj, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_lazy_refcounts, "lazy-refcounts", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_lazy_refcounts) {
        visit_type_bool(v, &(*obj)->lazy_refcounts, "lazy-refcounts", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pass_discard_request, "pass-discard-request", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pass_discard_request) {
        visit_type_bool(v, &(*obj)->pass_discard_request, "pass-discard-request", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pass_discard_snapshot, "pass-discard-snapshot", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pass_discard_snapshot) {
        visit_type_bool(v, &(*obj)->pass_discard_snapshot, "pass-discard-snapshot", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pass_discard_other, "pass-discard-other", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pass_discard_other) {
        visit_type_bool(v, &(*obj)->pass_discard_other, "pass-discard-other", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_overlap_check, "overlap-check", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_overlap_check) {
        visit_type_Qcow2OverlapChecks(v, &(*obj)->overlap_check, "overlap-check", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cache_size, "cache-size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cache_size) {
        visit_type_int(v, &(*obj)->cache_size, "cache-size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_l2_cache_size, "l2-cache-size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_l2_cache_size) {
        visit_type_int(v, &(*obj)->l2_cache_size, "l2-cache-size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_refcount_cache_size, "refcount-cache-size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_refcount_cache_size) {
        visit_type_int(v, &(*obj)->refcount_cache_size, "refcount-cache-size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cache_clean_interval, "cache-clean-interval", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cache_clean_interval) {
        visit_type_int(v, &(*obj)->cache_clean_interval, "cache-clean-interval", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsQcow2(Visitor *v, BlockdevOptionsQcow2 **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsQcow2", name, sizeof(BlockdevOptionsQcow2), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsQcow2_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsQuorum_fields(Visitor *v, BlockdevOptionsQuorum **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_blkverify, "blkverify", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_blkverify) {
        visit_type_bool(v, &(*obj)->blkverify, "blkverify", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_BlockdevRefList(v, &(*obj)->children, "children", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->vote_threshold, "vote-threshold", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_rewrite_corrupted, "rewrite-corrupted", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rewrite_corrupted) {
        visit_type_bool(v, &(*obj)->rewrite_corrupted, "rewrite-corrupted", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_read_pattern, "read-pattern", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_read_pattern) {
        visit_type_QuorumReadPattern(v, &(*obj)->read_pattern, "read-pattern", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsQuorum(Visitor *v, BlockdevOptionsQuorum **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsQuorum", name, sizeof(BlockdevOptionsQuorum), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsQuorum_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevOptionsVVFAT_fields(Visitor *v, BlockdevOptionsVVFAT **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->dir, "dir", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_fat_type, "fat-type", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_fat_type) {
        visit_type_int(v, &(*obj)->fat_type, "fat-type", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_floppy, "floppy", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_floppy) {
        visit_type_bool(v, &(*obj)->floppy, "floppy", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_label, "label", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_label) {
        visit_type_str(v, &(*obj)->label, "label", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_rw, "rw", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rw) {
        visit_type_bool(v, &(*obj)->rw, "rw", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevOptionsVVFAT(Visitor *v, BlockdevOptionsVVFAT **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevOptionsVVFAT", name, sizeof(BlockdevOptionsVVFAT), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevOptionsVVFAT_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_BlockdevRef(Visitor *v, BlockdevRef **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void**) obj, sizeof(BlockdevRef), &err);
    if (err) {
        goto out;
    }
    visit_get_next_type(v, (int*) &(*obj)->type, BlockdevRef_qtypes, name, &err);
    if (err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case BLOCKDEV_REF_KIND_DEFINITION:
        visit_type_BlockdevOptions(v, &(*obj)->u.definition, name, &err);
        break;
    case BLOCKDEV_REF_KIND_REFERENCE:
        visit_type_str(v, &(*obj)->u.reference, name, &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    visit_end_implicit_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_BlockdevRefKind(Visitor *v, BlockdevRefKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, BlockdevRefKind_lookup, "BlockdevRefKind", name, errp);
}

void visit_type_BlockdevRefList(Visitor *v, BlockdevRefList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        BlockdevRefList *native_i = (BlockdevRefList *)i;
        visit_type_BlockdevRef(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_BlockdevSnapshot_fields(Visitor *v, BlockdevSnapshot **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->node, "node", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->overlay, "overlay", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevSnapshot(Visitor *v, BlockdevSnapshot **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevSnapshot", name, sizeof(BlockdevSnapshot), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevSnapshot_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevSnapshotInternal_fields(Visitor *v, BlockdevSnapshotInternal **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevSnapshotInternal(Visitor *v, BlockdevSnapshotInternal **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevSnapshotInternal", name, sizeof(BlockdevSnapshotInternal), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevSnapshotInternal_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_BlockdevSnapshotSync_fields(Visitor *v, BlockdevSnapshotSync **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_device, "device", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_device) {
        visit_type_str(v, &(*obj)->device, "device", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_node_name) {
        visit_type_str(v, &(*obj)->node_name, "node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, &(*obj)->snapshot_file, "snapshot-file", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_snapshot_node_name, "snapshot-node-name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_snapshot_node_name) {
        visit_type_str(v, &(*obj)->snapshot_node_name, "snapshot-node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_format, "format", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_format) {
        visit_type_str(v, &(*obj)->format, "format", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_mode, "mode", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mode) {
        visit_type_NewImageMode(v, &(*obj)->mode, "mode", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_BlockdevSnapshotSync(Visitor *v, BlockdevSnapshotSync **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "BlockdevSnapshotSync", name, sizeof(BlockdevSnapshotSync), &err);
    if (!err) {
        if (*obj) {
            visit_type_BlockdevSnapshotSync_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ChardevBackend(Visitor *v, ChardevBackend **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevBackend", name, sizeof(ChardevBackend), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_ChardevBackendKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case CHARDEV_BACKEND_KIND_FILE:
        visit_type_ChardevFile(v, &(*obj)->u.file, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_SERIAL:
        visit_type_ChardevHostdev(v, &(*obj)->u.serial, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_PARALLEL:
        visit_type_ChardevHostdev(v, &(*obj)->u.parallel, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_PIPE:
        visit_type_ChardevHostdev(v, &(*obj)->u.pipe, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_SOCKET:
        visit_type_ChardevSocket(v, &(*obj)->u.socket, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_UDP:
        visit_type_ChardevUdp(v, &(*obj)->u.udp, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_PTY:
        visit_type_ChardevDummy(v, &(*obj)->u.pty, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_NULL:
        visit_type_ChardevDummy(v, &(*obj)->u.null, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_MUX:
        visit_type_ChardevMux(v, &(*obj)->u.mux, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_MSMOUSE:
        visit_type_ChardevDummy(v, &(*obj)->u.msmouse, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_BRAILLE:
        visit_type_ChardevDummy(v, &(*obj)->u.braille, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_TESTDEV:
        visit_type_ChardevDummy(v, &(*obj)->u.testdev, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_STDIO:
        visit_type_ChardevStdio(v, &(*obj)->u.stdio, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_CONSOLE:
        visit_type_ChardevDummy(v, &(*obj)->u.console, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_SPICEVMC:
        visit_type_ChardevSpiceChannel(v, &(*obj)->u.spicevmc, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_SPICEPORT:
        visit_type_ChardevSpicePort(v, &(*obj)->u.spiceport, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_VC:
        visit_type_ChardevVC(v, &(*obj)->u.vc, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_RINGBUF:
        visit_type_ChardevRingbuf(v, &(*obj)->u.ringbuf, "data", &err);
        break;
    case CHARDEV_BACKEND_KIND_MEMORY:
        visit_type_ChardevRingbuf(v, &(*obj)->u.memory, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_ChardevBackendInfo_fields(Visitor *v, ChardevBackendInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevBackendInfo(Visitor *v, ChardevBackendInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevBackendInfo", name, sizeof(ChardevBackendInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevBackendInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ChardevBackendInfoList(Visitor *v, ChardevBackendInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ChardevBackendInfoList *native_i = (ChardevBackendInfoList *)i;
        visit_type_ChardevBackendInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_ChardevBackendKind(Visitor *v, ChardevBackendKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ChardevBackendKind_lookup, "ChardevBackendKind", name, errp);
}

static void visit_type_ChardevDummy_fields(Visitor *v, ChardevDummy **obj, Error **errp)
{
    Error *err = NULL;

    error_propagate(errp, err);
}

void visit_type_ChardevDummy(Visitor *v, ChardevDummy **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevDummy", name, sizeof(ChardevDummy), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevDummy_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevFile_fields(Visitor *v, ChardevFile **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_in, "in", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_in) {
        visit_type_str(v, &(*obj)->in, "in", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, &(*obj)->out, "out", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevFile(Visitor *v, ChardevFile **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevFile", name, sizeof(ChardevFile), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevFile_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevHostdev_fields(Visitor *v, ChardevHostdev **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevHostdev(Visitor *v, ChardevHostdev **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevHostdev", name, sizeof(ChardevHostdev), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevHostdev_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevInfo_fields(Visitor *v, ChardevInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->label, "label", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->filename, "filename", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->frontend_open, "frontend-open", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevInfo(Visitor *v, ChardevInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevInfo", name, sizeof(ChardevInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ChardevInfoList(Visitor *v, ChardevInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ChardevInfoList *native_i = (ChardevInfoList *)i;
        visit_type_ChardevInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_ChardevMux_fields(Visitor *v, ChardevMux **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->chardev, "chardev", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevMux(Visitor *v, ChardevMux **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevMux", name, sizeof(ChardevMux), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevMux_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevReturn_fields(Visitor *v, ChardevReturn **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_pty, "pty", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pty) {
        visit_type_str(v, &(*obj)->pty, "pty", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevReturn(Visitor *v, ChardevReturn **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevReturn", name, sizeof(ChardevReturn), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevReturn_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevRingbuf_fields(Visitor *v, ChardevRingbuf **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_size, "size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_size) {
        visit_type_int(v, &(*obj)->size, "size", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevRingbuf(Visitor *v, ChardevRingbuf **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevRingbuf", name, sizeof(ChardevRingbuf), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevRingbuf_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevSocket_fields(Visitor *v, ChardevSocket **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SocketAddress(v, &(*obj)->addr, "addr", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_server, "server", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_server) {
        visit_type_bool(v, &(*obj)->server, "server", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_wait, "wait", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_wait) {
        visit_type_bool(v, &(*obj)->wait, "wait", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_nodelay, "nodelay", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_nodelay) {
        visit_type_bool(v, &(*obj)->nodelay, "nodelay", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_telnet, "telnet", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_telnet) {
        visit_type_bool(v, &(*obj)->telnet, "telnet", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_reconnect, "reconnect", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_reconnect) {
        visit_type_int(v, &(*obj)->reconnect, "reconnect", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevSocket(Visitor *v, ChardevSocket **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevSocket", name, sizeof(ChardevSocket), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevSocket_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevSpiceChannel_fields(Visitor *v, ChardevSpiceChannel **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevSpiceChannel(Visitor *v, ChardevSpiceChannel **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevSpiceChannel", name, sizeof(ChardevSpiceChannel), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevSpiceChannel_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevSpicePort_fields(Visitor *v, ChardevSpicePort **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->fqdn, "fqdn", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevSpicePort(Visitor *v, ChardevSpicePort **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevSpicePort", name, sizeof(ChardevSpicePort), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevSpicePort_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevStdio_fields(Visitor *v, ChardevStdio **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_signal, "signal", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_signal) {
        visit_type_bool(v, &(*obj)->signal, "signal", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevStdio(Visitor *v, ChardevStdio **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevStdio", name, sizeof(ChardevStdio), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevStdio_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevUdp_fields(Visitor *v, ChardevUdp **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SocketAddress(v, &(*obj)->remote, "remote", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_local, "local", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_local) {
        visit_type_SocketAddress(v, &(*obj)->local, "local", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevUdp(Visitor *v, ChardevUdp **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevUdp", name, sizeof(ChardevUdp), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevUdp_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ChardevVC_fields(Visitor *v, ChardevVC **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_width, "width", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_width) {
        visit_type_int(v, &(*obj)->width, "width", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_height, "height", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_height) {
        visit_type_int(v, &(*obj)->height, "height", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cols, "cols", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cols) {
        visit_type_int(v, &(*obj)->cols, "cols", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_rows, "rows", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rows) {
        visit_type_int(v, &(*obj)->rows, "rows", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ChardevVC(Visitor *v, ChardevVC **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ChardevVC", name, sizeof(ChardevVC), &err);
    if (!err) {
        if (*obj) {
            visit_type_ChardevVC_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_CommandInfo_fields(Visitor *v, CommandInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_CommandInfo(Visitor *v, CommandInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "CommandInfo", name, sizeof(CommandInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_CommandInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_CommandInfoList(Visitor *v, CommandInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        CommandInfoList *native_i = (CommandInfoList *)i;
        visit_type_CommandInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_CommandLineOptionInfo_fields(Visitor *v, CommandLineOptionInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->option, "option", &err);
    if (err) {
        goto out;
    }
    visit_type_CommandLineParameterInfoList(v, &(*obj)->parameters, "parameters", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_CommandLineOptionInfo(Visitor *v, CommandLineOptionInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "CommandLineOptionInfo", name, sizeof(CommandLineOptionInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_CommandLineOptionInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_CommandLineOptionInfoList(Visitor *v, CommandLineOptionInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        CommandLineOptionInfoList *native_i = (CommandLineOptionInfoList *)i;
        visit_type_CommandLineOptionInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_CommandLineParameterInfo_fields(Visitor *v, CommandLineParameterInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_CommandLineParameterType(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_help, "help", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_help) {
        visit_type_str(v, &(*obj)->help, "help", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_q_default, "default", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_q_default) {
        visit_type_str(v, &(*obj)->q_default, "default", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_CommandLineParameterInfo(Visitor *v, CommandLineParameterInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "CommandLineParameterInfo", name, sizeof(CommandLineParameterInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_CommandLineParameterInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_CommandLineParameterInfoList(Visitor *v, CommandLineParameterInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        CommandLineParameterInfoList *native_i = (CommandLineParameterInfoList *)i;
        visit_type_CommandLineParameterInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_CommandLineParameterType(Visitor *v, CommandLineParameterType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, CommandLineParameterType_lookup, "CommandLineParameterType", name, errp);
}

static void visit_type_CpuDefinitionInfo_fields(Visitor *v, CpuDefinitionInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_CpuDefinitionInfo(Visitor *v, CpuDefinitionInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "CpuDefinitionInfo", name, sizeof(CpuDefinitionInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_CpuDefinitionInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_CpuDefinitionInfoList(Visitor *v, CpuDefinitionInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        CpuDefinitionInfoList *native_i = (CpuDefinitionInfoList *)i;
        visit_type_CpuDefinitionInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_CpuInfo_fields(Visitor *v, CpuInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->CPU, "CPU", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->current, "current", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->halted, "halted", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->qom_path, "qom_path", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_pc, "pc", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pc) {
        visit_type_int(v, &(*obj)->pc, "pc", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_nip, "nip", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_nip) {
        visit_type_int(v, &(*obj)->nip, "nip", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_npc, "npc", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_npc) {
        visit_type_int(v, &(*obj)->npc, "npc", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_PC, "PC", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_PC) {
        visit_type_int(v, &(*obj)->PC, "PC", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->thread_id, "thread_id", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_CpuInfo(Visitor *v, CpuInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "CpuInfo", name, sizeof(CpuInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_CpuInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_CpuInfoList(Visitor *v, CpuInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        CpuInfoList *native_i = (CpuInfoList *)i;
        visit_type_CpuInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_DataFormat(Visitor *v, DataFormat *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, DataFormat_lookup, "DataFormat", name, errp);
}

static void visit_type_DevicePropertyInfo_fields(Visitor *v, DevicePropertyInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_description, "description", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_description) {
        visit_type_str(v, &(*obj)->description, "description", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_DevicePropertyInfo(Visitor *v, DevicePropertyInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "DevicePropertyInfo", name, sizeof(DevicePropertyInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_DevicePropertyInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_DevicePropertyInfoList(Visitor *v, DevicePropertyInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        DevicePropertyInfoList *native_i = (DevicePropertyInfoList *)i;
        visit_type_DevicePropertyInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_DirtyBitmapStatus(Visitor *v, DirtyBitmapStatus *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, DirtyBitmapStatus_lookup, "DirtyBitmapStatus", name, errp);
}

static void visit_type_DriveBackup_fields(Visitor *v, DriveBackup **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->target, "target", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_format, "format", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_format) {
        visit_type_str(v, &(*obj)->format, "format", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_MirrorSyncMode(v, &(*obj)->sync, "sync", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_mode, "mode", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mode) {
        visit_type_NewImageMode(v, &(*obj)->mode, "mode", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_speed, "speed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_speed) {
        visit_type_int(v, &(*obj)->speed, "speed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_bitmap, "bitmap", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_bitmap) {
        visit_type_str(v, &(*obj)->bitmap, "bitmap", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_on_source_error, "on-source-error", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_on_source_error) {
        visit_type_BlockdevOnError(v, &(*obj)->on_source_error, "on-source-error", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_on_target_error, "on-target-error", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_on_target_error) {
        visit_type_BlockdevOnError(v, &(*obj)->on_target_error, "on-target-error", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_DriveBackup(Visitor *v, DriveBackup **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "DriveBackup", name, sizeof(DriveBackup), &err);
    if (!err) {
        if (*obj) {
            visit_type_DriveBackup_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_DummyForceArrays_fields(Visitor *v, DummyForceArrays **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_X86CPUFeatureWordInfoList(v, &(*obj)->unused, "unused", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_DummyForceArrays(Visitor *v, DummyForceArrays **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "DummyForceArrays", name, sizeof(DummyForceArrays), &err);
    if (!err) {
        if (*obj) {
            visit_type_DummyForceArrays_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_DumpGuestMemoryCapability_fields(Visitor *v, DumpGuestMemoryCapability **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_DumpGuestMemoryFormatList(v, &(*obj)->formats, "formats", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_DumpGuestMemoryCapability(Visitor *v, DumpGuestMemoryCapability **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "DumpGuestMemoryCapability", name, sizeof(DumpGuestMemoryCapability), &err);
    if (!err) {
        if (*obj) {
            visit_type_DumpGuestMemoryCapability_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_DumpGuestMemoryFormat(Visitor *v, DumpGuestMemoryFormat *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, DumpGuestMemoryFormat_lookup, "DumpGuestMemoryFormat", name, errp);
}

void visit_type_DumpGuestMemoryFormatList(Visitor *v, DumpGuestMemoryFormatList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        DumpGuestMemoryFormatList *native_i = (DumpGuestMemoryFormatList *)i;
        visit_type_DumpGuestMemoryFormat(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_ErrorClass(Visitor *v, ErrorClass *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ErrorClass_lookup, "ErrorClass", name, errp);
}

static void visit_type_EventInfo_fields(Visitor *v, EventInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_EventInfo(Visitor *v, EventInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "EventInfo", name, sizeof(EventInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_EventInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_EventInfoList(Visitor *v, EventInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        EventInfoList *native_i = (EventInfoList *)i;
        visit_type_EventInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_FdsetFdInfo_fields(Visitor *v, FdsetFdInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->fd, "fd", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_opaque, "opaque", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_opaque) {
        visit_type_str(v, &(*obj)->opaque, "opaque", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_FdsetFdInfo(Visitor *v, FdsetFdInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "FdsetFdInfo", name, sizeof(FdsetFdInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_FdsetFdInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_FdsetFdInfoList(Visitor *v, FdsetFdInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        FdsetFdInfoList *native_i = (FdsetFdInfoList *)i;
        visit_type_FdsetFdInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_FdsetInfo_fields(Visitor *v, FdsetInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->fdset_id, "fdset-id", &err);
    if (err) {
        goto out;
    }
    visit_type_FdsetFdInfoList(v, &(*obj)->fds, "fds", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_FdsetInfo(Visitor *v, FdsetInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "FdsetInfo", name, sizeof(FdsetInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_FdsetInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_FdsetInfoList(Visitor *v, FdsetInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        FdsetInfoList *native_i = (FdsetInfoList *)i;
        visit_type_FdsetInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_GuestPanicAction(Visitor *v, GuestPanicAction *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, GuestPanicAction_lookup, "GuestPanicAction", name, errp);
}

void visit_type_HostMemPolicy(Visitor *v, HostMemPolicy *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, HostMemPolicy_lookup, "HostMemPolicy", name, errp);
}

static void visit_type_IOThreadInfo_fields(Visitor *v, IOThreadInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->thread_id, "thread-id", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_IOThreadInfo(Visitor *v, IOThreadInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "IOThreadInfo", name, sizeof(IOThreadInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_IOThreadInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_IOThreadInfoList(Visitor *v, IOThreadInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        IOThreadInfoList *native_i = (IOThreadInfoList *)i;
        visit_type_IOThreadInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_ImageCheck_fields(Visitor *v, ImageCheck **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->filename, "filename", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->format, "format", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->check_errors, "check-errors", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_image_end_offset, "image-end-offset", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_image_end_offset) {
        visit_type_int(v, &(*obj)->image_end_offset, "image-end-offset", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_corruptions, "corruptions", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_corruptions) {
        visit_type_int(v, &(*obj)->corruptions, "corruptions", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_leaks, "leaks", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_leaks) {
        visit_type_int(v, &(*obj)->leaks, "leaks", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_corruptions_fixed, "corruptions-fixed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_corruptions_fixed) {
        visit_type_int(v, &(*obj)->corruptions_fixed, "corruptions-fixed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_leaks_fixed, "leaks-fixed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_leaks_fixed) {
        visit_type_int(v, &(*obj)->leaks_fixed, "leaks-fixed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_total_clusters, "total-clusters", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_total_clusters) {
        visit_type_int(v, &(*obj)->total_clusters, "total-clusters", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_allocated_clusters, "allocated-clusters", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_allocated_clusters) {
        visit_type_int(v, &(*obj)->allocated_clusters, "allocated-clusters", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_fragmented_clusters, "fragmented-clusters", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_fragmented_clusters) {
        visit_type_int(v, &(*obj)->fragmented_clusters, "fragmented-clusters", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_compressed_clusters, "compressed-clusters", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_compressed_clusters) {
        visit_type_int(v, &(*obj)->compressed_clusters, "compressed-clusters", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ImageCheck(Visitor *v, ImageCheck **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ImageCheck", name, sizeof(ImageCheck), &err);
    if (!err) {
        if (*obj) {
            visit_type_ImageCheck_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ImageInfo_fields(Visitor *v, ImageInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->filename, "filename", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->format, "format", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_dirty_flag, "dirty-flag", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dirty_flag) {
        visit_type_bool(v, &(*obj)->dirty_flag, "dirty-flag", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_actual_size, "actual-size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_actual_size) {
        visit_type_int(v, &(*obj)->actual_size, "actual-size", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->virtual_size, "virtual-size", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_cluster_size, "cluster-size", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cluster_size) {
        visit_type_int(v, &(*obj)->cluster_size, "cluster-size", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_encrypted, "encrypted", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_encrypted) {
        visit_type_bool(v, &(*obj)->encrypted, "encrypted", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_compressed, "compressed", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_compressed) {
        visit_type_bool(v, &(*obj)->compressed, "compressed", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_backing_filename, "backing-filename", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing_filename) {
        visit_type_str(v, &(*obj)->backing_filename, "backing-filename", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_full_backing_filename, "full-backing-filename", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_full_backing_filename) {
        visit_type_str(v, &(*obj)->full_backing_filename, "full-backing-filename", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_backing_filename_format, "backing-filename-format", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing_filename_format) {
        visit_type_str(v, &(*obj)->backing_filename_format, "backing-filename-format", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_snapshots, "snapshots", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_snapshots) {
        visit_type_SnapshotInfoList(v, &(*obj)->snapshots, "snapshots", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_backing_image, "backing-image", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_backing_image) {
        visit_type_ImageInfo(v, &(*obj)->backing_image, "backing-image", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_format_specific, "format-specific", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_format_specific) {
        visit_type_ImageInfoSpecific(v, &(*obj)->format_specific, "format-specific", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_ImageInfo(Visitor *v, ImageInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ImageInfo", name, sizeof(ImageInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ImageInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ImageInfoList(Visitor *v, ImageInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ImageInfoList *native_i = (ImageInfoList *)i;
        visit_type_ImageInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_ImageInfoSpecific(Visitor *v, ImageInfoSpecific **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ImageInfoSpecific", name, sizeof(ImageInfoSpecific), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_ImageInfoSpecificKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case IMAGE_INFO_SPECIFIC_KIND_QCOW2:
        visit_type_ImageInfoSpecificQCow2(v, &(*obj)->u.qcow2, "data", &err);
        break;
    case IMAGE_INFO_SPECIFIC_KIND_VMDK:
        visit_type_ImageInfoSpecificVmdk(v, &(*obj)->u.vmdk, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_ImageInfoSpecificKind(Visitor *v, ImageInfoSpecificKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ImageInfoSpecificKind_lookup, "ImageInfoSpecificKind", name, errp);
}

static void visit_type_ImageInfoSpecificQCow2_fields(Visitor *v, ImageInfoSpecificQCow2 **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->compat, "compat", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_lazy_refcounts, "lazy-refcounts", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_lazy_refcounts) {
        visit_type_bool(v, &(*obj)->lazy_refcounts, "lazy-refcounts", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_corrupt, "corrupt", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_corrupt) {
        visit_type_bool(v, &(*obj)->corrupt, "corrupt", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->refcount_bits, "refcount-bits", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ImageInfoSpecificQCow2(Visitor *v, ImageInfoSpecificQCow2 **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ImageInfoSpecificQCow2", name, sizeof(ImageInfoSpecificQCow2), &err);
    if (!err) {
        if (*obj) {
            visit_type_ImageInfoSpecificQCow2_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_ImageInfoSpecificVmdk_fields(Visitor *v, ImageInfoSpecificVmdk **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->create_type, "create-type", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->cid, "cid", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->parent_cid, "parent-cid", &err);
    if (err) {
        goto out;
    }
    visit_type_ImageInfoList(v, &(*obj)->extents, "extents", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ImageInfoSpecificVmdk(Visitor *v, ImageInfoSpecificVmdk **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ImageInfoSpecificVmdk", name, sizeof(ImageInfoSpecificVmdk), &err);
    if (!err) {
        if (*obj) {
            visit_type_ImageInfoSpecificVmdk_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_InetSocketAddress_fields(Visitor *v, InetSocketAddress **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->host, "host", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->port, "port", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_to, "to", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_to) {
        visit_type_uint16(v, &(*obj)->to, "to", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ipv4, "ipv4", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ipv4) {
        visit_type_bool(v, &(*obj)->ipv4, "ipv4", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ipv6, "ipv6", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ipv6) {
        visit_type_bool(v, &(*obj)->ipv6, "ipv6", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_InetSocketAddress(Visitor *v, InetSocketAddress **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "InetSocketAddress", name, sizeof(InetSocketAddress), &err);
    if (!err) {
        if (*obj) {
            visit_type_InetSocketAddress_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_InputAxis(Visitor *v, InputAxis *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, InputAxis_lookup, "InputAxis", name, errp);
}

static void visit_type_InputBtnEvent_fields(Visitor *v, InputBtnEvent **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_InputButton(v, &(*obj)->button, "button", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->down, "down", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_InputBtnEvent(Visitor *v, InputBtnEvent **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "InputBtnEvent", name, sizeof(InputBtnEvent), &err);
    if (!err) {
        if (*obj) {
            visit_type_InputBtnEvent_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_InputButton(Visitor *v, InputButton *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, InputButton_lookup, "InputButton", name, errp);
}

void visit_type_InputEvent(Visitor *v, InputEvent **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "InputEvent", name, sizeof(InputEvent), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_InputEventKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case INPUT_EVENT_KIND_KEY:
        visit_type_InputKeyEvent(v, &(*obj)->u.key, "data", &err);
        break;
    case INPUT_EVENT_KIND_BTN:
        visit_type_InputBtnEvent(v, &(*obj)->u.btn, "data", &err);
        break;
    case INPUT_EVENT_KIND_REL:
        visit_type_InputMoveEvent(v, &(*obj)->u.rel, "data", &err);
        break;
    case INPUT_EVENT_KIND_ABS:
        visit_type_InputMoveEvent(v, &(*obj)->u.abs, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_InputEventKind(Visitor *v, InputEventKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, InputEventKind_lookup, "InputEventKind", name, errp);
}

void visit_type_InputEventList(Visitor *v, InputEventList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        InputEventList *native_i = (InputEventList *)i;
        visit_type_InputEvent(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_InputKeyEvent_fields(Visitor *v, InputKeyEvent **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_KeyValue(v, &(*obj)->key, "key", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->down, "down", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_InputKeyEvent(Visitor *v, InputKeyEvent **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "InputKeyEvent", name, sizeof(InputKeyEvent), &err);
    if (!err) {
        if (*obj) {
            visit_type_InputKeyEvent_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_InputMoveEvent_fields(Visitor *v, InputMoveEvent **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_InputAxis(v, &(*obj)->axis, "axis", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->value, "value", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_InputMoveEvent(Visitor *v, InputMoveEvent **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "InputMoveEvent", name, sizeof(InputMoveEvent), &err);
    if (!err) {
        if (*obj) {
            visit_type_InputMoveEvent_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_IoOperationType(Visitor *v, IoOperationType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, IoOperationType_lookup, "IoOperationType", name, errp);
}

void visit_type_JSONType(Visitor *v, JSONType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, JSONType_lookup, "JSONType", name, errp);
}

void visit_type_KeyValue(Visitor *v, KeyValue **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "KeyValue", name, sizeof(KeyValue), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_KeyValueKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case KEY_VALUE_KIND_NUMBER:
        visit_type_int(v, &(*obj)->u.number, "data", &err);
        break;
    case KEY_VALUE_KIND_QCODE:
        visit_type_QKeyCode(v, &(*obj)->u.qcode, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_KeyValueKind(Visitor *v, KeyValueKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, KeyValueKind_lookup, "KeyValueKind", name, errp);
}

void visit_type_KeyValueList(Visitor *v, KeyValueList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        KeyValueList *native_i = (KeyValueList *)i;
        visit_type_KeyValue(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_KvmInfo_fields(Visitor *v, KvmInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, &(*obj)->enabled, "enabled", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->present, "present", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_KvmInfo(Visitor *v, KvmInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "KvmInfo", name, sizeof(KvmInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_KvmInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_LostTickPolicy(Visitor *v, LostTickPolicy *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, LostTickPolicy_lookup, "LostTickPolicy", name, errp);
}

static void visit_type_MachineInfo_fields(Visitor *v, MachineInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_alias, "alias", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_alias) {
        visit_type_str(v, &(*obj)->alias, "alias", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_is_default, "is-default", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_is_default) {
        visit_type_bool(v, &(*obj)->is_default, "is-default", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->cpu_max, "cpu-max", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_MachineInfo(Visitor *v, MachineInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MachineInfo", name, sizeof(MachineInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_MachineInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MachineInfoList(Visitor *v, MachineInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        MachineInfoList *native_i = (MachineInfoList *)i;
        visit_type_MachineInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_Memdev_fields(Visitor *v, Memdev **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_size(v, &(*obj)->size, "size", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->merge, "merge", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->dump, "dump", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->prealloc, "prealloc", &err);
    if (err) {
        goto out;
    }
    visit_type_uint16List(v, &(*obj)->host_nodes, "host-nodes", &err);
    if (err) {
        goto out;
    }
    visit_type_HostMemPolicy(v, &(*obj)->policy, "policy", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_Memdev(Visitor *v, Memdev **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "Memdev", name, sizeof(Memdev), &err);
    if (!err) {
        if (*obj) {
            visit_type_Memdev_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MemdevList(Visitor *v, MemdevList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        MemdevList *native_i = (MemdevList *)i;
        visit_type_Memdev(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_MemoryDeviceInfo(Visitor *v, MemoryDeviceInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MemoryDeviceInfo", name, sizeof(MemoryDeviceInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_MemoryDeviceInfoKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case MEMORY_DEVICE_INFO_KIND_DIMM:
        visit_type_PCDIMMDeviceInfo(v, &(*obj)->u.dimm, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_MemoryDeviceInfoKind(Visitor *v, MemoryDeviceInfoKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, MemoryDeviceInfoKind_lookup, "MemoryDeviceInfoKind", name, errp);
}

void visit_type_MemoryDeviceInfoList(Visitor *v, MemoryDeviceInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        MemoryDeviceInfoList *native_i = (MemoryDeviceInfoList *)i;
        visit_type_MemoryDeviceInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_MigrationCapability(Visitor *v, MigrationCapability *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, MigrationCapability_lookup, "MigrationCapability", name, errp);
}

static void visit_type_MigrationCapabilityStatus_fields(Visitor *v, MigrationCapabilityStatus **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_MigrationCapability(v, &(*obj)->capability, "capability", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->state, "state", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_MigrationCapabilityStatus(Visitor *v, MigrationCapabilityStatus **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MigrationCapabilityStatus", name, sizeof(MigrationCapabilityStatus), &err);
    if (!err) {
        if (*obj) {
            visit_type_MigrationCapabilityStatus_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MigrationCapabilityStatusList(Visitor *v, MigrationCapabilityStatusList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        MigrationCapabilityStatusList *native_i = (MigrationCapabilityStatusList *)i;
        visit_type_MigrationCapabilityStatus(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_MigrationInfo_fields(Visitor *v, MigrationInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_status, "status", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_status) {
        visit_type_MigrationStatus(v, &(*obj)->status, "status", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ram, "ram", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ram) {
        visit_type_MigrationStats(v, &(*obj)->ram, "ram", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_disk, "disk", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_disk) {
        visit_type_MigrationStats(v, &(*obj)->disk, "disk", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_xbzrle_cache, "xbzrle-cache", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_xbzrle_cache) {
        visit_type_XBZRLECacheStats(v, &(*obj)->xbzrle_cache, "xbzrle-cache", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_total_time, "total-time", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_total_time) {
        visit_type_int(v, &(*obj)->total_time, "total-time", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_expected_downtime, "expected-downtime", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_expected_downtime) {
        visit_type_int(v, &(*obj)->expected_downtime, "expected-downtime", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_downtime, "downtime", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_downtime) {
        visit_type_int(v, &(*obj)->downtime, "downtime", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_setup_time, "setup-time", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_setup_time) {
        visit_type_int(v, &(*obj)->setup_time, "setup-time", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_x_cpu_throttle_percentage, "x-cpu-throttle-percentage", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_x_cpu_throttle_percentage) {
        visit_type_int(v, &(*obj)->x_cpu_throttle_percentage, "x-cpu-throttle-percentage", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_MigrationInfo(Visitor *v, MigrationInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MigrationInfo", name, sizeof(MigrationInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_MigrationInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MigrationParameter(Visitor *v, MigrationParameter *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, MigrationParameter_lookup, "MigrationParameter", name, errp);
}

static void visit_type_MigrationParameters_fields(Visitor *v, MigrationParameters **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->compress_level, "compress-level", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->compress_threads, "compress-threads", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->decompress_threads, "decompress-threads", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->x_cpu_throttle_initial, "x-cpu-throttle-initial", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->x_cpu_throttle_increment, "x-cpu-throttle-increment", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_MigrationParameters(Visitor *v, MigrationParameters **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MigrationParameters", name, sizeof(MigrationParameters), &err);
    if (!err) {
        if (*obj) {
            visit_type_MigrationParameters_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_MigrationStats_fields(Visitor *v, MigrationStats **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->transferred, "transferred", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->remaining, "remaining", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->total, "total", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->duplicate, "duplicate", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->skipped, "skipped", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->normal, "normal", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->normal_bytes, "normal-bytes", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->dirty_pages_rate, "dirty-pages-rate", &err);
    if (err) {
        goto out;
    }
    visit_type_number(v, &(*obj)->mbps, "mbps", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->dirty_sync_count, "dirty-sync-count", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_MigrationStats(Visitor *v, MigrationStats **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MigrationStats", name, sizeof(MigrationStats), &err);
    if (!err) {
        if (*obj) {
            visit_type_MigrationStats_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MigrationStatus(Visitor *v, MigrationStatus *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, MigrationStatus_lookup, "MigrationStatus", name, errp);
}

void visit_type_MirrorSyncMode(Visitor *v, MirrorSyncMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, MirrorSyncMode_lookup, "MirrorSyncMode", name, errp);
}

static void visit_type_MouseInfo_fields(Visitor *v, MouseInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->index, "index", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->current, "current", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->absolute, "absolute", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_MouseInfo(Visitor *v, MouseInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "MouseInfo", name, sizeof(MouseInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_MouseInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_MouseInfoList(Visitor *v, MouseInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        MouseInfoList *native_i = (MouseInfoList *)i;
        visit_type_MouseInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_NameInfo_fields(Visitor *v, NameInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_name, "name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_name) {
        visit_type_str(v, &(*obj)->name, "name", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NameInfo(Visitor *v, NameInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NameInfo", name, sizeof(NameInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_NameInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_NetClientOptions(Visitor *v, NetClientOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetClientOptions", name, sizeof(NetClientOptions), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_NetClientOptionsKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case NET_CLIENT_OPTIONS_KIND_NONE:
        visit_type_NetdevNoneOptions(v, &(*obj)->u.none, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_NIC:
        visit_type_NetLegacyNicOptions(v, &(*obj)->u.nic, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_USER:
        visit_type_NetdevUserOptions(v, &(*obj)->u.user, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_TAP:
        visit_type_NetdevTapOptions(v, &(*obj)->u.tap, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_L2TPV3:
        visit_type_NetdevL2TPv3Options(v, &(*obj)->u.l2tpv3, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_SOCKET:
        visit_type_NetdevSocketOptions(v, &(*obj)->u.socket, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_VDE:
        visit_type_NetdevVdeOptions(v, &(*obj)->u.vde, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_DUMP:
        visit_type_NetdevDumpOptions(v, &(*obj)->u.dump, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_BRIDGE:
        visit_type_NetdevBridgeOptions(v, &(*obj)->u.bridge, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_HUBPORT:
        visit_type_NetdevHubPortOptions(v, &(*obj)->u.hubport, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_NETMAP:
        visit_type_NetdevNetmapOptions(v, &(*obj)->u.netmap, "data", &err);
        break;
    case NET_CLIENT_OPTIONS_KIND_VHOST_USER:
        visit_type_NetdevVhostUserOptions(v, &(*obj)->u.vhost_user, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_NetClientOptionsKind(Visitor *v, NetClientOptionsKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, NetClientOptionsKind_lookup, "NetClientOptionsKind", name, errp);
}

void visit_type_NetFilterDirection(Visitor *v, NetFilterDirection *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, NetFilterDirection_lookup, "NetFilterDirection", name, errp);
}

static void visit_type_NetLegacy_fields(Visitor *v, NetLegacy **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_vlan, "vlan", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vlan) {
        visit_type_int32(v, &(*obj)->vlan, "vlan", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_id, "id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_id) {
        visit_type_str(v, &(*obj)->id, "id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_name, "name", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_name) {
        visit_type_str(v, &(*obj)->name, "name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_NetClientOptions(v, &(*obj)->opts, "opts", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetLegacy(Visitor *v, NetLegacy **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetLegacy", name, sizeof(NetLegacy), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetLegacy_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetLegacyNicOptions_fields(Visitor *v, NetLegacyNicOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_netdev, "netdev", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_netdev) {
        visit_type_str(v, &(*obj)->netdev, "netdev", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_macaddr, "macaddr", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_macaddr) {
        visit_type_str(v, &(*obj)->macaddr, "macaddr", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_model, "model", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_model) {
        visit_type_str(v, &(*obj)->model, "model", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_addr, "addr", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_addr) {
        visit_type_str(v, &(*obj)->addr, "addr", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vectors, "vectors", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vectors) {
        visit_type_uint32(v, &(*obj)->vectors, "vectors", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetLegacyNicOptions(Visitor *v, NetLegacyNicOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetLegacyNicOptions", name, sizeof(NetLegacyNicOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetLegacyNicOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_Netdev_fields(Visitor *v, Netdev **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_NetClientOptions(v, &(*obj)->opts, "opts", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_Netdev(Visitor *v, Netdev **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "Netdev", name, sizeof(Netdev), &err);
    if (!err) {
        if (*obj) {
            visit_type_Netdev_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevBridgeOptions_fields(Visitor *v, NetdevBridgeOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_br, "br", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_br) {
        visit_type_str(v, &(*obj)->br, "br", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_helper, "helper", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_helper) {
        visit_type_str(v, &(*obj)->helper, "helper", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevBridgeOptions(Visitor *v, NetdevBridgeOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevBridgeOptions", name, sizeof(NetdevBridgeOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevBridgeOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevDumpOptions_fields(Visitor *v, NetdevDumpOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_len, "len", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_len) {
        visit_type_size(v, &(*obj)->len, "len", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_file, "file", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_file) {
        visit_type_str(v, &(*obj)->file, "file", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevDumpOptions(Visitor *v, NetdevDumpOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevDumpOptions", name, sizeof(NetdevDumpOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevDumpOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevHubPortOptions_fields(Visitor *v, NetdevHubPortOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int32(v, &(*obj)->hubid, "hubid", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevHubPortOptions(Visitor *v, NetdevHubPortOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevHubPortOptions", name, sizeof(NetdevHubPortOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevHubPortOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevL2TPv3Options_fields(Visitor *v, NetdevL2TPv3Options **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->src, "src", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->dst, "dst", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_srcport, "srcport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_srcport) {
        visit_type_str(v, &(*obj)->srcport, "srcport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_dstport, "dstport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dstport) {
        visit_type_str(v, &(*obj)->dstport, "dstport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ipv6, "ipv6", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ipv6) {
        visit_type_bool(v, &(*obj)->ipv6, "ipv6", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_udp, "udp", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_udp) {
        visit_type_bool(v, &(*obj)->udp, "udp", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cookie64, "cookie64", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cookie64) {
        visit_type_bool(v, &(*obj)->cookie64, "cookie64", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_counter, "counter", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_counter) {
        visit_type_bool(v, &(*obj)->counter, "counter", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pincounter, "pincounter", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pincounter) {
        visit_type_bool(v, &(*obj)->pincounter, "pincounter", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_txcookie, "txcookie", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_txcookie) {
        visit_type_uint64(v, &(*obj)->txcookie, "txcookie", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_rxcookie, "rxcookie", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rxcookie) {
        visit_type_uint64(v, &(*obj)->rxcookie, "rxcookie", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_uint32(v, &(*obj)->txsession, "txsession", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_rxsession, "rxsession", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_rxsession) {
        visit_type_uint32(v, &(*obj)->rxsession, "rxsession", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_offset, "offset", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_offset) {
        visit_type_uint32(v, &(*obj)->offset, "offset", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevL2TPv3Options(Visitor *v, NetdevL2TPv3Options **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevL2TPv3Options", name, sizeof(NetdevL2TPv3Options), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevL2TPv3Options_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevNetmapOptions_fields(Visitor *v, NetdevNetmapOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->ifname, "ifname", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_devname, "devname", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_devname) {
        visit_type_str(v, &(*obj)->devname, "devname", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevNetmapOptions(Visitor *v, NetdevNetmapOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevNetmapOptions", name, sizeof(NetdevNetmapOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevNetmapOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevNoneOptions_fields(Visitor *v, NetdevNoneOptions **obj, Error **errp)
{
    Error *err = NULL;

    error_propagate(errp, err);
}

void visit_type_NetdevNoneOptions(Visitor *v, NetdevNoneOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevNoneOptions", name, sizeof(NetdevNoneOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevNoneOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevSocketOptions_fields(Visitor *v, NetdevSocketOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_fd, "fd", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_fd) {
        visit_type_str(v, &(*obj)->fd, "fd", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_listen, "listen", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_listen) {
        visit_type_str(v, &(*obj)->listen, "listen", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_connect, "connect", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_connect) {
        visit_type_str(v, &(*obj)->connect, "connect", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_mcast, "mcast", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mcast) {
        visit_type_str(v, &(*obj)->mcast, "mcast", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_localaddr, "localaddr", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_localaddr) {
        visit_type_str(v, &(*obj)->localaddr, "localaddr", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_udp, "udp", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_udp) {
        visit_type_str(v, &(*obj)->udp, "udp", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevSocketOptions(Visitor *v, NetdevSocketOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevSocketOptions", name, sizeof(NetdevSocketOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevSocketOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevTapOptions_fields(Visitor *v, NetdevTapOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_ifname, "ifname", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ifname) {
        visit_type_str(v, &(*obj)->ifname, "ifname", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_fd, "fd", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_fd) {
        visit_type_str(v, &(*obj)->fd, "fd", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_fds, "fds", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_fds) {
        visit_type_str(v, &(*obj)->fds, "fds", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_script, "script", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_script) {
        visit_type_str(v, &(*obj)->script, "script", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_downscript, "downscript", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_downscript) {
        visit_type_str(v, &(*obj)->downscript, "downscript", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_helper, "helper", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_helper) {
        visit_type_str(v, &(*obj)->helper, "helper", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_sndbuf, "sndbuf", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_sndbuf) {
        visit_type_size(v, &(*obj)->sndbuf, "sndbuf", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vnet_hdr, "vnet_hdr", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vnet_hdr) {
        visit_type_bool(v, &(*obj)->vnet_hdr, "vnet_hdr", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vhost, "vhost", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vhost) {
        visit_type_bool(v, &(*obj)->vhost, "vhost", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vhostfd, "vhostfd", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vhostfd) {
        visit_type_str(v, &(*obj)->vhostfd, "vhostfd", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vhostfds, "vhostfds", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vhostfds) {
        visit_type_str(v, &(*obj)->vhostfds, "vhostfds", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vhostforce, "vhostforce", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vhostforce) {
        visit_type_bool(v, &(*obj)->vhostforce, "vhostforce", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_queues, "queues", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_queues) {
        visit_type_uint32(v, &(*obj)->queues, "queues", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevTapOptions(Visitor *v, NetdevTapOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevTapOptions", name, sizeof(NetdevTapOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevTapOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevUserOptions_fields(Visitor *v, NetdevUserOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_hostname, "hostname", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_hostname) {
        visit_type_str(v, &(*obj)->hostname, "hostname", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_q_restrict, "restrict", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_q_restrict) {
        visit_type_bool(v, &(*obj)->q_restrict, "restrict", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip, "ip", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip) {
        visit_type_str(v, &(*obj)->ip, "ip", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_net, "net", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_net) {
        visit_type_str(v, &(*obj)->net, "net", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_host, "host", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_host) {
        visit_type_str(v, &(*obj)->host, "host", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tftp, "tftp", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tftp) {
        visit_type_str(v, &(*obj)->tftp, "tftp", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_bootfile, "bootfile", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_bootfile) {
        visit_type_str(v, &(*obj)->bootfile, "bootfile", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_dhcpstart, "dhcpstart", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dhcpstart) {
        visit_type_str(v, &(*obj)->dhcpstart, "dhcpstart", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_dns, "dns", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dns) {
        visit_type_str(v, &(*obj)->dns, "dns", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_dnssearch, "dnssearch", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_dnssearch) {
        visit_type_StringList(v, &(*obj)->dnssearch, "dnssearch", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_smb, "smb", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_smb) {
        visit_type_str(v, &(*obj)->smb, "smb", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_smbserver, "smbserver", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_smbserver) {
        visit_type_str(v, &(*obj)->smbserver, "smbserver", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_hostfwd, "hostfwd", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_hostfwd) {
        visit_type_StringList(v, &(*obj)->hostfwd, "hostfwd", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_guestfwd, "guestfwd", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_guestfwd) {
        visit_type_StringList(v, &(*obj)->guestfwd, "guestfwd", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevUserOptions(Visitor *v, NetdevUserOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevUserOptions", name, sizeof(NetdevUserOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevUserOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevVdeOptions_fields(Visitor *v, NetdevVdeOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_sock, "sock", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_sock) {
        visit_type_str(v, &(*obj)->sock, "sock", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_port, "port", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_port) {
        visit_type_uint16(v, &(*obj)->port, "port", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_group, "group", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_group) {
        visit_type_str(v, &(*obj)->group, "group", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_mode, "mode", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mode) {
        visit_type_uint16(v, &(*obj)->mode, "mode", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevVdeOptions(Visitor *v, NetdevVdeOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevVdeOptions", name, sizeof(NetdevVdeOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevVdeOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_NetdevVhostUserOptions_fields(Visitor *v, NetdevVhostUserOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->chardev, "chardev", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_vhostforce, "vhostforce", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vhostforce) {
        visit_type_bool(v, &(*obj)->vhostforce, "vhostforce", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_queues, "queues", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_queues) {
        visit_type_int(v, &(*obj)->queues, "queues", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NetdevVhostUserOptions(Visitor *v, NetdevVhostUserOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NetdevVhostUserOptions", name, sizeof(NetdevVhostUserOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NetdevVhostUserOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_NetworkAddressFamily(Visitor *v, NetworkAddressFamily *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, NetworkAddressFamily_lookup, "NetworkAddressFamily", name, errp);
}

void visit_type_NewImageMode(Visitor *v, NewImageMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, NewImageMode_lookup, "NewImageMode", name, errp);
}

static void visit_type_NumaNodeOptions_fields(Visitor *v, NumaNodeOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_nodeid, "nodeid", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_nodeid) {
        visit_type_uint16(v, &(*obj)->nodeid, "nodeid", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cpus, "cpus", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cpus) {
        visit_type_uint16List(v, &(*obj)->cpus, "cpus", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_mem, "mem", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mem) {
        visit_type_size(v, &(*obj)->mem, "mem", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_memdev, "memdev", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_memdev) {
        visit_type_str(v, &(*obj)->memdev, "memdev", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_NumaNodeOptions(Visitor *v, NumaNodeOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NumaNodeOptions", name, sizeof(NumaNodeOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_NumaNodeOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_NumaOptions(Visitor *v, NumaOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "NumaOptions", name, sizeof(NumaOptions), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_NumaOptionsKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case NUMA_OPTIONS_KIND_NODE:
        visit_type_NumaNodeOptions(v, &(*obj)->u.node, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_NumaOptionsKind(Visitor *v, NumaOptionsKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, NumaOptionsKind_lookup, "NumaOptionsKind", name, errp);
}

static void visit_type_ObjectPropertyInfo_fields(Visitor *v, ObjectPropertyInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ObjectPropertyInfo(Visitor *v, ObjectPropertyInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ObjectPropertyInfo", name, sizeof(ObjectPropertyInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ObjectPropertyInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ObjectPropertyInfoList(Visitor *v, ObjectPropertyInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ObjectPropertyInfoList *native_i = (ObjectPropertyInfoList *)i;
        visit_type_ObjectPropertyInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_ObjectTypeInfo_fields(Visitor *v, ObjectTypeInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_ObjectTypeInfo(Visitor *v, ObjectTypeInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "ObjectTypeInfo", name, sizeof(ObjectTypeInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_ObjectTypeInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_ObjectTypeInfoList(Visitor *v, ObjectTypeInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        ObjectTypeInfoList *native_i = (ObjectTypeInfoList *)i;
        visit_type_ObjectTypeInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_OnOffAuto(Visitor *v, OnOffAuto *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, OnOffAuto_lookup, "OnOffAuto", name, errp);
}

static void visit_type_PCDIMMDeviceInfo_fields(Visitor *v, PCDIMMDeviceInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_id, "id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_id) {
        visit_type_str(v, &(*obj)->id, "id", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->addr, "addr", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->size, "size", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->slot, "slot", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->node, "node", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->memdev, "memdev", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->hotplugged, "hotplugged", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->hotpluggable, "hotpluggable", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PCDIMMDeviceInfo(Visitor *v, PCDIMMDeviceInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PCDIMMDeviceInfo", name, sizeof(PCDIMMDeviceInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_PCDIMMDeviceInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciBridgeInfo_fields(Visitor *v, PciBridgeInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_PciBusInfo(v, &(*obj)->bus, "bus", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_devices, "devices", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_devices) {
        visit_type_PciDeviceInfoList(v, &(*obj)->devices, "devices", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciBridgeInfo(Visitor *v, PciBridgeInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciBridgeInfo", name, sizeof(PciBridgeInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciBridgeInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciBusInfo_fields(Visitor *v, PciBusInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->number, "number", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->secondary, "secondary", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->subordinate, "subordinate", &err);
    if (err) {
        goto out;
    }
    visit_type_PciMemoryRange(v, &(*obj)->io_range, "io_range", &err);
    if (err) {
        goto out;
    }
    visit_type_PciMemoryRange(v, &(*obj)->memory_range, "memory_range", &err);
    if (err) {
        goto out;
    }
    visit_type_PciMemoryRange(v, &(*obj)->prefetchable_range, "prefetchable_range", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciBusInfo(Visitor *v, PciBusInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciBusInfo", name, sizeof(PciBusInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciBusInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciDeviceClass_fields(Visitor *v, PciDeviceClass **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_desc, "desc", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_desc) {
        visit_type_str(v, &(*obj)->desc, "desc", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_int(v, &(*obj)->q_class, "class", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciDeviceClass(Visitor *v, PciDeviceClass **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciDeviceClass", name, sizeof(PciDeviceClass), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciDeviceClass_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciDeviceId_fields(Visitor *v, PciDeviceId **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->vendor, "vendor", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciDeviceId(Visitor *v, PciDeviceId **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciDeviceId", name, sizeof(PciDeviceId), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciDeviceId_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciDeviceInfo_fields(Visitor *v, PciDeviceInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->bus, "bus", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->slot, "slot", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->function, "function", &err);
    if (err) {
        goto out;
    }
    visit_type_PciDeviceClass(v, &(*obj)->class_info, "class_info", &err);
    if (err) {
        goto out;
    }
    visit_type_PciDeviceId(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_irq, "irq", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_irq) {
        visit_type_int(v, &(*obj)->irq, "irq", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, &(*obj)->qdev_id, "qdev_id", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_pci_bridge, "pci_bridge", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pci_bridge) {
        visit_type_PciBridgeInfo(v, &(*obj)->pci_bridge, "pci_bridge", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_PciMemoryRegionList(v, &(*obj)->regions, "regions", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciDeviceInfo(Visitor *v, PciDeviceInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciDeviceInfo", name, sizeof(PciDeviceInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciDeviceInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_PciDeviceInfoList(Visitor *v, PciDeviceInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        PciDeviceInfoList *native_i = (PciDeviceInfoList *)i;
        visit_type_PciDeviceInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_PciInfo_fields(Visitor *v, PciInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->bus, "bus", &err);
    if (err) {
        goto out;
    }
    visit_type_PciDeviceInfoList(v, &(*obj)->devices, "devices", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciInfo(Visitor *v, PciInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciInfo", name, sizeof(PciInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_PciInfoList(Visitor *v, PciInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        PciInfoList *native_i = (PciInfoList *)i;
        visit_type_PciInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_PciMemoryRange_fields(Visitor *v, PciMemoryRange **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->base, "base", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->limit, "limit", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciMemoryRange(Visitor *v, PciMemoryRange **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciMemoryRange", name, sizeof(PciMemoryRange), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciMemoryRange_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_PciMemoryRegion_fields(Visitor *v, PciMemoryRegion **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->bar, "bar", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->address, "address", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->size, "size", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_prefetch, "prefetch", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_prefetch) {
        visit_type_bool(v, &(*obj)->prefetch, "prefetch", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_mem_type_64, "mem_type_64", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_mem_type_64) {
        visit_type_bool(v, &(*obj)->mem_type_64, "mem_type_64", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_PciMemoryRegion(Visitor *v, PciMemoryRegion **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "PciMemoryRegion", name, sizeof(PciMemoryRegion), &err);
    if (!err) {
        if (*obj) {
            visit_type_PciMemoryRegion_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_PciMemoryRegionList(Visitor *v, PciMemoryRegionList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        PciMemoryRegionList *native_i = (PciMemoryRegionList *)i;
        visit_type_PciMemoryRegion(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_PreallocMode(Visitor *v, PreallocMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, PreallocMode_lookup, "PreallocMode", name, errp);
}

void visit_type_QCryptoTLSCredsEndpoint(Visitor *v, QCryptoTLSCredsEndpoint *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, QCryptoTLSCredsEndpoint_lookup, "QCryptoTLSCredsEndpoint", name, errp);
}

void visit_type_QKeyCode(Visitor *v, QKeyCode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, QKeyCode_lookup, "QKeyCode", name, errp);
}

static void visit_type_Qcow2OverlapCheckFlags_fields(Visitor *v, Qcow2OverlapCheckFlags **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_q_template, "template", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_q_template) {
        visit_type_Qcow2OverlapCheckMode(v, &(*obj)->q_template, "template", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_main_header, "main-header", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_main_header) {
        visit_type_bool(v, &(*obj)->main_header, "main-header", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_active_l1, "active-l1", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_active_l1) {
        visit_type_bool(v, &(*obj)->active_l1, "active-l1", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_active_l2, "active-l2", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_active_l2) {
        visit_type_bool(v, &(*obj)->active_l2, "active-l2", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_refcount_table, "refcount-table", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_refcount_table) {
        visit_type_bool(v, &(*obj)->refcount_table, "refcount-table", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_refcount_block, "refcount-block", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_refcount_block) {
        visit_type_bool(v, &(*obj)->refcount_block, "refcount-block", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_snapshot_table, "snapshot-table", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_snapshot_table) {
        visit_type_bool(v, &(*obj)->snapshot_table, "snapshot-table", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_inactive_l1, "inactive-l1", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_inactive_l1) {
        visit_type_bool(v, &(*obj)->inactive_l1, "inactive-l1", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_inactive_l2, "inactive-l2", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_inactive_l2) {
        visit_type_bool(v, &(*obj)->inactive_l2, "inactive-l2", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_Qcow2OverlapCheckFlags(Visitor *v, Qcow2OverlapCheckFlags **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "Qcow2OverlapCheckFlags", name, sizeof(Qcow2OverlapCheckFlags), &err);
    if (!err) {
        if (*obj) {
            visit_type_Qcow2OverlapCheckFlags_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_Qcow2OverlapCheckMode(Visitor *v, Qcow2OverlapCheckMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, Qcow2OverlapCheckMode_lookup, "Qcow2OverlapCheckMode", name, errp);
}

void visit_type_Qcow2OverlapChecks(Visitor *v, Qcow2OverlapChecks **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void**) obj, sizeof(Qcow2OverlapChecks), &err);
    if (err) {
        goto out;
    }
    visit_get_next_type(v, (int*) &(*obj)->type, Qcow2OverlapChecks_qtypes, name, &err);
    if (err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case QCOW2_OVERLAP_CHECKS_KIND_FLAGS:
        visit_type_Qcow2OverlapCheckFlags(v, &(*obj)->u.flags, name, &err);
        break;
    case QCOW2_OVERLAP_CHECKS_KIND_MODE:
        visit_type_Qcow2OverlapCheckMode(v, &(*obj)->u.mode, name, &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    visit_end_implicit_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_Qcow2OverlapChecksKind(Visitor *v, Qcow2OverlapChecksKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, Qcow2OverlapChecksKind_lookup, "Qcow2OverlapChecksKind", name, errp);
}

void visit_type_QuorumReadPattern(Visitor *v, QuorumReadPattern *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, QuorumReadPattern_lookup, "QuorumReadPattern", name, errp);
}

void visit_type_ReplayMode(Visitor *v, ReplayMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, ReplayMode_lookup, "ReplayMode", name, errp);
}

static void visit_type_RockerOfDpaFlow_fields(Visitor *v, RockerOfDpaFlow **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint64(v, &(*obj)->cookie, "cookie", &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, &(*obj)->hits, "hits", &err);
    if (err) {
        goto out;
    }
    visit_type_RockerOfDpaFlowKey(v, &(*obj)->key, "key", &err);
    if (err) {
        goto out;
    }
    visit_type_RockerOfDpaFlowMask(v, &(*obj)->mask, "mask", &err);
    if (err) {
        goto out;
    }
    visit_type_RockerOfDpaFlowAction(v, &(*obj)->action, "action", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaFlow(Visitor *v, RockerOfDpaFlow **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerOfDpaFlow", name, sizeof(RockerOfDpaFlow), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerOfDpaFlow_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_RockerOfDpaFlowAction_fields(Visitor *v, RockerOfDpaFlowAction **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_goto_tbl, "goto-tbl", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_goto_tbl) {
        visit_type_uint32(v, &(*obj)->goto_tbl, "goto-tbl", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_group_id, "group-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_group_id) {
        visit_type_uint32(v, &(*obj)->group_id, "group-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tunnel_lport, "tunnel-lport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tunnel_lport) {
        visit_type_uint32(v, &(*obj)->tunnel_lport, "tunnel-lport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vlan_id, "vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vlan_id) {
        visit_type_uint16(v, &(*obj)->vlan_id, "vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_new_vlan_id, "new-vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_new_vlan_id) {
        visit_type_uint16(v, &(*obj)->new_vlan_id, "new-vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_out_pport, "out-pport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_out_pport) {
        visit_type_uint32(v, &(*obj)->out_pport, "out-pport", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaFlowAction(Visitor *v, RockerOfDpaFlowAction **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerOfDpaFlowAction", name, sizeof(RockerOfDpaFlowAction), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerOfDpaFlowAction_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_RockerOfDpaFlowKey_fields(Visitor *v, RockerOfDpaFlowKey **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint32(v, &(*obj)->priority, "priority", &err);
    if (err) {
        goto out;
    }
    visit_type_uint32(v, &(*obj)->tbl_id, "tbl-id", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_in_pport, "in-pport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_in_pport) {
        visit_type_uint32(v, &(*obj)->in_pport, "in-pport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tunnel_id, "tunnel-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tunnel_id) {
        visit_type_uint32(v, &(*obj)->tunnel_id, "tunnel-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vlan_id, "vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vlan_id) {
        visit_type_uint16(v, &(*obj)->vlan_id, "vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_eth_type, "eth-type", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_eth_type) {
        visit_type_uint16(v, &(*obj)->eth_type, "eth-type", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_eth_src, "eth-src", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_eth_src) {
        visit_type_str(v, &(*obj)->eth_src, "eth-src", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_eth_dst, "eth-dst", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_eth_dst) {
        visit_type_str(v, &(*obj)->eth_dst, "eth-dst", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip_proto, "ip-proto", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip_proto) {
        visit_type_uint8(v, &(*obj)->ip_proto, "ip-proto", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip_tos, "ip-tos", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip_tos) {
        visit_type_uint8(v, &(*obj)->ip_tos, "ip-tos", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip_dst, "ip-dst", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip_dst) {
        visit_type_str(v, &(*obj)->ip_dst, "ip-dst", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaFlowKey(Visitor *v, RockerOfDpaFlowKey **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerOfDpaFlowKey", name, sizeof(RockerOfDpaFlowKey), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerOfDpaFlowKey_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaFlowList(Visitor *v, RockerOfDpaFlowList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        RockerOfDpaFlowList *native_i = (RockerOfDpaFlowList *)i;
        visit_type_RockerOfDpaFlow(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_RockerOfDpaFlowMask_fields(Visitor *v, RockerOfDpaFlowMask **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_in_pport, "in-pport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_in_pport) {
        visit_type_uint32(v, &(*obj)->in_pport, "in-pport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tunnel_id, "tunnel-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tunnel_id) {
        visit_type_uint32(v, &(*obj)->tunnel_id, "tunnel-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_vlan_id, "vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vlan_id) {
        visit_type_uint16(v, &(*obj)->vlan_id, "vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_eth_src, "eth-src", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_eth_src) {
        visit_type_str(v, &(*obj)->eth_src, "eth-src", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_eth_dst, "eth-dst", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_eth_dst) {
        visit_type_str(v, &(*obj)->eth_dst, "eth-dst", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip_proto, "ip-proto", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip_proto) {
        visit_type_uint8(v, &(*obj)->ip_proto, "ip-proto", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ip_tos, "ip-tos", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ip_tos) {
        visit_type_uint8(v, &(*obj)->ip_tos, "ip-tos", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaFlowMask(Visitor *v, RockerOfDpaFlowMask **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerOfDpaFlowMask", name, sizeof(RockerOfDpaFlowMask), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerOfDpaFlowMask_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_RockerOfDpaGroup_fields(Visitor *v, RockerOfDpaGroup **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_uint32(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_uint8(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_vlan_id, "vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vlan_id) {
        visit_type_uint16(v, &(*obj)->vlan_id, "vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pport, "pport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pport) {
        visit_type_uint32(v, &(*obj)->pport, "pport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_index, "index", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_index) {
        visit_type_uint32(v, &(*obj)->index, "index", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_out_pport, "out-pport", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_out_pport) {
        visit_type_uint32(v, &(*obj)->out_pport, "out-pport", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_group_id, "group-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_group_id) {
        visit_type_uint32(v, &(*obj)->group_id, "group-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_set_vlan_id, "set-vlan-id", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_set_vlan_id) {
        visit_type_uint16(v, &(*obj)->set_vlan_id, "set-vlan-id", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_pop_vlan, "pop-vlan", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_pop_vlan) {
        visit_type_uint8(v, &(*obj)->pop_vlan, "pop-vlan", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_group_ids, "group-ids", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_group_ids) {
        visit_type_uint32List(v, &(*obj)->group_ids, "group-ids", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_set_eth_src, "set-eth-src", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_set_eth_src) {
        visit_type_str(v, &(*obj)->set_eth_src, "set-eth-src", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_set_eth_dst, "set-eth-dst", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_set_eth_dst) {
        visit_type_str(v, &(*obj)->set_eth_dst, "set-eth-dst", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_ttl_check, "ttl-check", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_ttl_check) {
        visit_type_uint8(v, &(*obj)->ttl_check, "ttl-check", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaGroup(Visitor *v, RockerOfDpaGroup **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerOfDpaGroup", name, sizeof(RockerOfDpaGroup), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerOfDpaGroup_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_RockerOfDpaGroupList(Visitor *v, RockerOfDpaGroupList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        RockerOfDpaGroupList *native_i = (RockerOfDpaGroupList *)i;
        visit_type_RockerOfDpaGroup(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_RockerPort_fields(Visitor *v, RockerPort **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->enabled, "enabled", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->link_up, "link-up", &err);
    if (err) {
        goto out;
    }
    visit_type_uint32(v, &(*obj)->speed, "speed", &err);
    if (err) {
        goto out;
    }
    visit_type_RockerPortDuplex(v, &(*obj)->duplex, "duplex", &err);
    if (err) {
        goto out;
    }
    visit_type_RockerPortAutoneg(v, &(*obj)->autoneg, "autoneg", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerPort(Visitor *v, RockerPort **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerPort", name, sizeof(RockerPort), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerPort_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_RockerPortAutoneg(Visitor *v, RockerPortAutoneg *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, RockerPortAutoneg_lookup, "RockerPortAutoneg", name, errp);
}

void visit_type_RockerPortDuplex(Visitor *v, RockerPortDuplex *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, RockerPortDuplex_lookup, "RockerPortDuplex", name, errp);
}

void visit_type_RockerPortList(Visitor *v, RockerPortList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        RockerPortList *native_i = (RockerPortList *)i;
        visit_type_RockerPort(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_RockerSwitch_fields(Visitor *v, RockerSwitch **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_uint32(v, &(*obj)->ports, "ports", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_RockerSwitch(Visitor *v, RockerSwitch **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RockerSwitch", name, sizeof(RockerSwitch), &err);
    if (!err) {
        if (*obj) {
            visit_type_RockerSwitch_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_RunState(Visitor *v, RunState *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, RunState_lookup, "RunState", name, errp);
}

static void visit_type_RxFilterInfo_fields(Visitor *v, RxFilterInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->promiscuous, "promiscuous", &err);
    if (err) {
        goto out;
    }
    visit_type_RxState(v, &(*obj)->multicast, "multicast", &err);
    if (err) {
        goto out;
    }
    visit_type_RxState(v, &(*obj)->unicast, "unicast", &err);
    if (err) {
        goto out;
    }
    visit_type_RxState(v, &(*obj)->vlan, "vlan", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->broadcast_allowed, "broadcast-allowed", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->multicast_overflow, "multicast-overflow", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->unicast_overflow, "unicast-overflow", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->main_mac, "main-mac", &err);
    if (err) {
        goto out;
    }
    visit_type_intList(v, &(*obj)->vlan_table, "vlan-table", &err);
    if (err) {
        goto out;
    }
    visit_type_strList(v, &(*obj)->unicast_table, "unicast-table", &err);
    if (err) {
        goto out;
    }
    visit_type_strList(v, &(*obj)->multicast_table, "multicast-table", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_RxFilterInfo(Visitor *v, RxFilterInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "RxFilterInfo", name, sizeof(RxFilterInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_RxFilterInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_RxFilterInfoList(Visitor *v, RxFilterInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        RxFilterInfoList *native_i = (RxFilterInfoList *)i;
        visit_type_RxFilterInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_RxState(Visitor *v, RxState *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, RxState_lookup, "RxState", name, errp);
}

static void visit_type_SchemaInfoBase_fields(Visitor *v, SchemaInfoBase **obj, Error **errp);

static void visit_type_SchemaInfoBuiltin_fields(Visitor *v, SchemaInfoBuiltin **obj, Error **errp);

static void visit_type_implicit_SchemaInfoBuiltin(Visitor *v, SchemaInfoBuiltin **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoBuiltin), &err);
    if (!err) {
        visit_type_SchemaInfoBuiltin_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoEnum_fields(Visitor *v, SchemaInfoEnum **obj, Error **errp);

static void visit_type_implicit_SchemaInfoEnum(Visitor *v, SchemaInfoEnum **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoEnum), &err);
    if (!err) {
        visit_type_SchemaInfoEnum_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoArray_fields(Visitor *v, SchemaInfoArray **obj, Error **errp);

static void visit_type_implicit_SchemaInfoArray(Visitor *v, SchemaInfoArray **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoArray), &err);
    if (!err) {
        visit_type_SchemaInfoArray_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoObject_fields(Visitor *v, SchemaInfoObject **obj, Error **errp);

static void visit_type_implicit_SchemaInfoObject(Visitor *v, SchemaInfoObject **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoObject), &err);
    if (!err) {
        visit_type_SchemaInfoObject_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoAlternate_fields(Visitor *v, SchemaInfoAlternate **obj, Error **errp);

static void visit_type_implicit_SchemaInfoAlternate(Visitor *v, SchemaInfoAlternate **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoAlternate), &err);
    if (!err) {
        visit_type_SchemaInfoAlternate_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoCommand_fields(Visitor *v, SchemaInfoCommand **obj, Error **errp);

static void visit_type_implicit_SchemaInfoCommand(Visitor *v, SchemaInfoCommand **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoCommand), &err);
    if (!err) {
        visit_type_SchemaInfoCommand_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoEvent_fields(Visitor *v, SchemaInfoEvent **obj, Error **errp);

static void visit_type_implicit_SchemaInfoEvent(Visitor *v, SchemaInfoEvent **obj, Error **errp)
{
    Error *err = NULL;

    visit_start_implicit_struct(v, (void **)obj, sizeof(SchemaInfoEvent), &err);
    if (!err) {
        visit_type_SchemaInfoEvent_fields(v, obj, errp);
        visit_end_implicit_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SchemaInfo(Visitor *v, SchemaInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfo", name, sizeof(SchemaInfo), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_SchemaInfoBase_fields(v, (SchemaInfoBase **)obj, &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->meta_type) {
    case SCHEMA_META_TYPE_BUILTIN:
        visit_type_implicit_SchemaInfoBuiltin(v, &(*obj)->u.builtin, &err);
        break;
    case SCHEMA_META_TYPE_ENUM:
        visit_type_implicit_SchemaInfoEnum(v, &(*obj)->u.q_enum, &err);
        break;
    case SCHEMA_META_TYPE_ARRAY:
        visit_type_implicit_SchemaInfoArray(v, &(*obj)->u.array, &err);
        break;
    case SCHEMA_META_TYPE_OBJECT:
        visit_type_implicit_SchemaInfoObject(v, &(*obj)->u.object, &err);
        break;
    case SCHEMA_META_TYPE_ALTERNATE:
        visit_type_implicit_SchemaInfoAlternate(v, &(*obj)->u.alternate, &err);
        break;
    case SCHEMA_META_TYPE_COMMAND:
        visit_type_implicit_SchemaInfoCommand(v, &(*obj)->u.command, &err);
        break;
    case SCHEMA_META_TYPE_EVENT:
        visit_type_implicit_SchemaInfoEvent(v, &(*obj)->u.event, &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoAlternate_fields(Visitor *v, SchemaInfoAlternate **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SchemaInfoAlternateMemberList(v, &(*obj)->members, "members", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoAlternate(Visitor *v, SchemaInfoAlternate **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoAlternate", name, sizeof(SchemaInfoAlternate), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoAlternate_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoAlternateMember_fields(Visitor *v, SchemaInfoAlternateMember **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoAlternateMember(Visitor *v, SchemaInfoAlternateMember **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoAlternateMember", name, sizeof(SchemaInfoAlternateMember), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoAlternateMember_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SchemaInfoAlternateMemberList(Visitor *v, SchemaInfoAlternateMemberList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SchemaInfoAlternateMemberList *native_i = (SchemaInfoAlternateMemberList *)i;
        visit_type_SchemaInfoAlternateMember(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoArray_fields(Visitor *v, SchemaInfoArray **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->element_type, "element-type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoArray(Visitor *v, SchemaInfoArray **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoArray", name, sizeof(SchemaInfoArray), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoArray_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoBase_fields(Visitor *v, SchemaInfoBase **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_SchemaMetaType(v, &(*obj)->meta_type, "meta-type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoBase(Visitor *v, SchemaInfoBase **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoBase", name, sizeof(SchemaInfoBase), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoBase_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoBuiltin_fields(Visitor *v, SchemaInfoBuiltin **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_JSONType(v, &(*obj)->json_type, "json-type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoBuiltin(Visitor *v, SchemaInfoBuiltin **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoBuiltin", name, sizeof(SchemaInfoBuiltin), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoBuiltin_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoCommand_fields(Visitor *v, SchemaInfoCommand **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->arg_type, "arg-type", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->ret_type, "ret-type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoCommand(Visitor *v, SchemaInfoCommand **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoCommand", name, sizeof(SchemaInfoCommand), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoCommand_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoEnum_fields(Visitor *v, SchemaInfoEnum **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_strList(v, &(*obj)->values, "values", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoEnum(Visitor *v, SchemaInfoEnum **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoEnum", name, sizeof(SchemaInfoEnum), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoEnum_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoEvent_fields(Visitor *v, SchemaInfoEvent **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->arg_type, "arg-type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoEvent(Visitor *v, SchemaInfoEvent **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoEvent", name, sizeof(SchemaInfoEvent), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoEvent_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SchemaInfoList(Visitor *v, SchemaInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SchemaInfoList *native_i = (SchemaInfoList *)i;
        visit_type_SchemaInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoObject_fields(Visitor *v, SchemaInfoObject **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SchemaInfoObjectMemberList(v, &(*obj)->members, "members", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_tag, "tag", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tag) {
        visit_type_str(v, &(*obj)->tag, "tag", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_variants, "variants", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_variants) {
        visit_type_SchemaInfoObjectVariantList(v, &(*obj)->variants, "variants", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoObject(Visitor *v, SchemaInfoObject **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoObject", name, sizeof(SchemaInfoObject), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoObject_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoObjectMember_fields(Visitor *v, SchemaInfoObjectMember **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_q_default, "default", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_q_default) {
        visit_type_any(v, &(*obj)->q_default, "default", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoObjectMember(Visitor *v, SchemaInfoObjectMember **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoObjectMember", name, sizeof(SchemaInfoObjectMember), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoObjectMember_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SchemaInfoObjectMemberList(Visitor *v, SchemaInfoObjectMemberList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SchemaInfoObjectMemberList *native_i = (SchemaInfoObjectMemberList *)i;
        visit_type_SchemaInfoObjectMember(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_SchemaInfoObjectVariant_fields(Visitor *v, SchemaInfoObjectVariant **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->q_case, "case", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SchemaInfoObjectVariant(Visitor *v, SchemaInfoObjectVariant **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SchemaInfoObjectVariant", name, sizeof(SchemaInfoObjectVariant), &err);
    if (!err) {
        if (*obj) {
            visit_type_SchemaInfoObjectVariant_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SchemaInfoObjectVariantList(Visitor *v, SchemaInfoObjectVariantList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SchemaInfoObjectVariantList *native_i = (SchemaInfoObjectVariantList *)i;
        visit_type_SchemaInfoObjectVariant(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_SchemaMetaType(Visitor *v, SchemaMetaType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, SchemaMetaType_lookup, "SchemaMetaType", name, errp);
}

static void visit_type_SnapshotInfo_fields(Visitor *v, SnapshotInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->vm_state_size, "vm-state-size", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->date_sec, "date-sec", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->date_nsec, "date-nsec", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->vm_clock_sec, "vm-clock-sec", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->vm_clock_nsec, "vm-clock-nsec", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SnapshotInfo(Visitor *v, SnapshotInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SnapshotInfo", name, sizeof(SnapshotInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_SnapshotInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SnapshotInfoList(Visitor *v, SnapshotInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SnapshotInfoList *native_i = (SnapshotInfoList *)i;
        visit_type_SnapshotInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_SocketAddress(Visitor *v, SocketAddress **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SocketAddress", name, sizeof(SocketAddress), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_SocketAddressKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case SOCKET_ADDRESS_KIND_INET:
        visit_type_InetSocketAddress(v, &(*obj)->u.inet, "data", &err);
        break;
    case SOCKET_ADDRESS_KIND_UNIX:
        visit_type_UnixSocketAddress(v, &(*obj)->u.q_unix, "data", &err);
        break;
    case SOCKET_ADDRESS_KIND_FD:
        visit_type_String(v, &(*obj)->u.fd, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_SocketAddressKind(Visitor *v, SocketAddressKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, SocketAddressKind_lookup, "SocketAddressKind", name, errp);
}

static void visit_type_SpiceBasicInfo_fields(Visitor *v, SpiceBasicInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->host, "host", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->port, "port", &err);
    if (err) {
        goto out;
    }
    visit_type_NetworkAddressFamily(v, &(*obj)->family, "family", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SpiceBasicInfo(Visitor *v, SpiceBasicInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SpiceBasicInfo", name, sizeof(SpiceBasicInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_SpiceBasicInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_SpiceChannel_fields(Visitor *v, SpiceChannel **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SpiceBasicInfo_fields(v, (SpiceBasicInfo **)obj, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->connection_id, "connection-id", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->channel_type, "channel-type", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->channel_id, "channel-id", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->tls, "tls", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_SpiceChannel(Visitor *v, SpiceChannel **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SpiceChannel", name, sizeof(SpiceChannel), &err);
    if (!err) {
        if (*obj) {
            visit_type_SpiceChannel_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SpiceChannelList(Visitor *v, SpiceChannelList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        SpiceChannelList *native_i = (SpiceChannelList *)i;
        visit_type_SpiceChannel(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_SpiceInfo_fields(Visitor *v, SpiceInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, &(*obj)->enabled, "enabled", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->migrated, "migrated", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_host, "host", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_host) {
        visit_type_str(v, &(*obj)->host, "host", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_port, "port", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_port) {
        visit_type_int(v, &(*obj)->port, "port", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_tls_port, "tls-port", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_tls_port) {
        visit_type_int(v, &(*obj)->tls_port, "tls-port", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_auth, "auth", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_auth) {
        visit_type_str(v, &(*obj)->auth, "auth", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_compiled_version, "compiled-version", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_compiled_version) {
        visit_type_str(v, &(*obj)->compiled_version, "compiled-version", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_SpiceQueryMouseMode(v, &(*obj)->mouse_mode, "mouse-mode", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_channels, "channels", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_channels) {
        visit_type_SpiceChannelList(v, &(*obj)->channels, "channels", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_SpiceInfo(Visitor *v, SpiceInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SpiceInfo", name, sizeof(SpiceInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_SpiceInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_SpiceQueryMouseMode(Visitor *v, SpiceQueryMouseMode *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, SpiceQueryMouseMode_lookup, "SpiceQueryMouseMode", name, errp);
}

static void visit_type_SpiceServerInfo_fields(Visitor *v, SpiceServerInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_SpiceBasicInfo_fields(v, (SpiceBasicInfo **)obj, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_auth, "auth", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_auth) {
        visit_type_str(v, &(*obj)->auth, "auth", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_SpiceServerInfo(Visitor *v, SpiceServerInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "SpiceServerInfo", name, sizeof(SpiceServerInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_SpiceServerInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_StatusInfo_fields(Visitor *v, StatusInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, &(*obj)->running, "running", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->singlestep, "singlestep", &err);
    if (err) {
        goto out;
    }
    visit_type_RunState(v, &(*obj)->status, "status", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_StatusInfo(Visitor *v, StatusInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "StatusInfo", name, sizeof(StatusInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_StatusInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_String_fields(Visitor *v, String **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->str, "str", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_String(Visitor *v, String **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "String", name, sizeof(String), &err);
    if (!err) {
        if (*obj) {
            visit_type_String_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_StringList(Visitor *v, StringList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        StringList *native_i = (StringList *)i;
        visit_type_String(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_TPMInfo_fields(Visitor *v, TPMInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_TpmModel(v, &(*obj)->model, "model", &err);
    if (err) {
        goto out;
    }
    visit_type_TpmTypeOptions(v, &(*obj)->options, "options", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_TPMInfo(Visitor *v, TPMInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TPMInfo", name, sizeof(TPMInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_TPMInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_TPMInfoList(Visitor *v, TPMInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        TPMInfoList *native_i = (TPMInfoList *)i;
        visit_type_TPMInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_TPMPassthroughOptions_fields(Visitor *v, TPMPassthroughOptions **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_path, "path", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_path) {
        visit_type_str(v, &(*obj)->path, "path", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_cancel_path, "cancel-path", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cancel_path) {
        visit_type_str(v, &(*obj)->cancel_path, "cancel-path", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_TPMPassthroughOptions(Visitor *v, TPMPassthroughOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TPMPassthroughOptions", name, sizeof(TPMPassthroughOptions), &err);
    if (!err) {
        if (*obj) {
            visit_type_TPMPassthroughOptions_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_TargetInfo_fields(Visitor *v, TargetInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->arch, "arch", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_TargetInfo(Visitor *v, TargetInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TargetInfo", name, sizeof(TargetInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_TargetInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_TpmModel(Visitor *v, TpmModel *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, TpmModel_lookup, "TpmModel", name, errp);
}

void visit_type_TpmModelList(Visitor *v, TpmModelList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        TpmModelList *native_i = (TpmModelList *)i;
        visit_type_TpmModel(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_TpmType(Visitor *v, TpmType *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, TpmType_lookup, "TpmType", name, errp);
}

void visit_type_TpmTypeList(Visitor *v, TpmTypeList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        TpmTypeList *native_i = (TpmTypeList *)i;
        visit_type_TpmType(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_TpmTypeOptions(Visitor *v, TpmTypeOptions **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TpmTypeOptions", name, sizeof(TpmTypeOptions), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_TpmTypeOptionsKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case TPM_TYPE_OPTIONS_KIND_PASSTHROUGH:
        visit_type_TPMPassthroughOptions(v, &(*obj)->u.passthrough, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_TpmTypeOptionsKind(Visitor *v, TpmTypeOptionsKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, TpmTypeOptionsKind_lookup, "TpmTypeOptionsKind", name, errp);
}

static void visit_type_TraceEventInfo_fields(Visitor *v, TraceEventInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->name, "name", &err);
    if (err) {
        goto out;
    }
    visit_type_TraceEventState(v, &(*obj)->state, "state", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_TraceEventInfo(Visitor *v, TraceEventInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TraceEventInfo", name, sizeof(TraceEventInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_TraceEventInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_TraceEventInfoList(Visitor *v, TraceEventInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        TraceEventInfoList *native_i = (TraceEventInfoList *)i;
        visit_type_TraceEventInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_TraceEventState(Visitor *v, TraceEventState *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, TraceEventState_lookup, "TraceEventState", name, errp);
}

void visit_type_TransactionAction(Visitor *v, TransactionAction **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TransactionAction", name, sizeof(TransactionAction), &err);
    if (err) {
        goto out;
    }
    if (!*obj) {
        goto out_obj;
    }
    visit_type_TransactionActionKind(v, &(*obj)->type, "type", &err);
    if (err) {
        goto out_obj;
    }
    if (!visit_start_union(v, !!(*obj)->u.data, &err) || err) {
        goto out_obj;
    }
    switch ((*obj)->type) {
    case TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT:
        visit_type_BlockdevSnapshot(v, &(*obj)->u.blockdev_snapshot, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT_SYNC:
        visit_type_BlockdevSnapshotSync(v, &(*obj)->u.blockdev_snapshot_sync, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_DRIVE_BACKUP:
        visit_type_DriveBackup(v, &(*obj)->u.drive_backup, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_BLOCKDEV_BACKUP:
        visit_type_BlockdevBackup(v, &(*obj)->u.blockdev_backup, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_ABORT:
        visit_type_Abort(v, &(*obj)->u.abort, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_BLOCKDEV_SNAPSHOT_INTERNAL_SYNC:
        visit_type_BlockdevSnapshotInternal(v, &(*obj)->u.blockdev_snapshot_internal_sync, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_BLOCK_DIRTY_BITMAP_ADD:
        visit_type_BlockDirtyBitmapAdd(v, &(*obj)->u.block_dirty_bitmap_add, "data", &err);
        break;
    case TRANSACTION_ACTION_KIND_BLOCK_DIRTY_BITMAP_CLEAR:
        visit_type_BlockDirtyBitmap(v, &(*obj)->u.block_dirty_bitmap_clear, "data", &err);
        break;
    default:
        abort();
    }
out_obj:
    error_propagate(errp, err);
    err = NULL;
    if (*obj) {
        visit_end_union(v, !!(*obj)->u.data, &err);
    }
    error_propagate(errp, err);
    err = NULL;
    visit_end_struct(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_TransactionActionKind(Visitor *v, TransactionActionKind *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, TransactionActionKind_lookup, "TransactionActionKind", name, errp);
}

void visit_type_TransactionActionList(Visitor *v, TransactionActionList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        TransactionActionList *native_i = (TransactionActionList *)i;
        visit_type_TransactionAction(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_TransactionProperties_fields(Visitor *v, TransactionProperties **obj, Error **errp)
{
    Error *err = NULL;

    visit_optional(v, &(*obj)->has_completion_mode, "completion-mode", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_completion_mode) {
        visit_type_ActionCompletionMode(v, &(*obj)->completion_mode, "completion-mode", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_TransactionProperties(Visitor *v, TransactionProperties **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "TransactionProperties", name, sizeof(TransactionProperties), &err);
    if (!err) {
        if (*obj) {
            visit_type_TransactionProperties_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_UnixSocketAddress_fields(Visitor *v, UnixSocketAddress **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->path, "path", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_UnixSocketAddress(Visitor *v, UnixSocketAddress **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "UnixSocketAddress", name, sizeof(UnixSocketAddress), &err);
    if (!err) {
        if (*obj) {
            visit_type_UnixSocketAddress_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_UuidInfo_fields(Visitor *v, UuidInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->UUID, "UUID", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_UuidInfo(Visitor *v, UuidInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "UuidInfo", name, sizeof(UuidInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_UuidInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_VersionInfo_fields(Visitor *v, VersionInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_VersionTriple(v, &(*obj)->qemu, "qemu", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->package, "package", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_VersionInfo(Visitor *v, VersionInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VersionInfo", name, sizeof(VersionInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_VersionInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_VersionTriple_fields(Visitor *v, VersionTriple **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->major, "major", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->minor, "minor", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->micro, "micro", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_VersionTriple(Visitor *v, VersionTriple **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VersionTriple", name, sizeof(VersionTriple), &err);
    if (!err) {
        if (*obj) {
            visit_type_VersionTriple_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_VncBasicInfo_fields(Visitor *v, VncBasicInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->host, "host", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, &(*obj)->service, "service", &err);
    if (err) {
        goto out;
    }
    visit_type_NetworkAddressFamily(v, &(*obj)->family, "family", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &(*obj)->websocket, "websocket", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_VncBasicInfo(Visitor *v, VncBasicInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VncBasicInfo", name, sizeof(VncBasicInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_VncBasicInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_VncBasicInfoList(Visitor *v, VncBasicInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        VncBasicInfoList *native_i = (VncBasicInfoList *)i;
        visit_type_VncBasicInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_VncClientInfo_fields(Visitor *v, VncClientInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_VncBasicInfo_fields(v, (VncBasicInfo **)obj, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_x509_dname, "x509_dname", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_x509_dname) {
        visit_type_str(v, &(*obj)->x509_dname, "x509_dname", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_sasl_username, "sasl_username", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_sasl_username) {
        visit_type_str(v, &(*obj)->sasl_username, "sasl_username", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_VncClientInfo(Visitor *v, VncClientInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VncClientInfo", name, sizeof(VncClientInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_VncClientInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_VncClientInfoList(Visitor *v, VncClientInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        VncClientInfoList *native_i = (VncClientInfoList *)i;
        visit_type_VncClientInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

static void visit_type_VncInfo_fields(Visitor *v, VncInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_bool(v, &(*obj)->enabled, "enabled", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_host, "host", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_host) {
        visit_type_str(v, &(*obj)->host, "host", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_family, "family", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_family) {
        visit_type_NetworkAddressFamily(v, &(*obj)->family, "family", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_service, "service", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_service) {
        visit_type_str(v, &(*obj)->service, "service", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_auth, "auth", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_auth) {
        visit_type_str(v, &(*obj)->auth, "auth", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_clients, "clients", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_clients) {
        visit_type_VncClientInfoList(v, &(*obj)->clients, "clients", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_VncInfo(Visitor *v, VncInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VncInfo", name, sizeof(VncInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_VncInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

static void visit_type_VncInfo2_fields(Visitor *v, VncInfo2 **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_str(v, &(*obj)->id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_VncBasicInfoList(v, &(*obj)->server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_VncClientInfoList(v, &(*obj)->clients, "clients", &err);
    if (err) {
        goto out;
    }
    visit_type_VncPrimaryAuth(v, &(*obj)->auth, "auth", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_vencrypt, "vencrypt", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_vencrypt) {
        visit_type_VncVencryptSubAuth(v, &(*obj)->vencrypt, "vencrypt", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &(*obj)->has_display, "display", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_display) {
        visit_type_str(v, &(*obj)->display, "display", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_VncInfo2(Visitor *v, VncInfo2 **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VncInfo2", name, sizeof(VncInfo2), &err);
    if (!err) {
        if (*obj) {
            visit_type_VncInfo2_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_VncInfo2List(Visitor *v, VncInfo2List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        VncInfo2List *native_i = (VncInfo2List *)i;
        visit_type_VncInfo2(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_VncPrimaryAuth(Visitor *v, VncPrimaryAuth *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, VncPrimaryAuth_lookup, "VncPrimaryAuth", name, errp);
}

static void visit_type_VncServerInfo_fields(Visitor *v, VncServerInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_VncBasicInfo_fields(v, (VncBasicInfo **)obj, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_auth, "auth", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_auth) {
        visit_type_str(v, &(*obj)->auth, "auth", &err);
        if (err) {
            goto out;
        }
    }

out:
    error_propagate(errp, err);
}

void visit_type_VncServerInfo(Visitor *v, VncServerInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "VncServerInfo", name, sizeof(VncServerInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_VncServerInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_VncVencryptSubAuth(Visitor *v, VncVencryptSubAuth *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, VncVencryptSubAuth_lookup, "VncVencryptSubAuth", name, errp);
}

void visit_type_WatchdogExpirationAction(Visitor *v, WatchdogExpirationAction *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, WatchdogExpirationAction_lookup, "WatchdogExpirationAction", name, errp);
}

static void visit_type_X86CPUFeatureWordInfo_fields(Visitor *v, X86CPUFeatureWordInfo **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->cpuid_input_eax, "cpuid-input-eax", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &(*obj)->has_cpuid_input_ecx, "cpuid-input-ecx", &err);
    if (err) {
        goto out;
    }
    if ((*obj)->has_cpuid_input_ecx) {
        visit_type_int(v, &(*obj)->cpuid_input_ecx, "cpuid-input-ecx", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_X86CPURegister32(v, &(*obj)->cpuid_register, "cpuid-register", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->features, "features", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_X86CPUFeatureWordInfo(Visitor *v, X86CPUFeatureWordInfo **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "X86CPUFeatureWordInfo", name, sizeof(X86CPUFeatureWordInfo), &err);
    if (!err) {
        if (*obj) {
            visit_type_X86CPUFeatureWordInfo_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_X86CPUFeatureWordInfoList(Visitor *v, X86CPUFeatureWordInfoList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        X86CPUFeatureWordInfoList *native_i = (X86CPUFeatureWordInfoList *)i;
        visit_type_X86CPUFeatureWordInfo(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_X86CPURegister32(Visitor *v, X86CPURegister32 *obj, const char *name, Error **errp)
{
    visit_type_enum(v, (int *)obj, X86CPURegister32_lookup, "X86CPURegister32", name, errp);
}

static void visit_type_XBZRLECacheStats_fields(Visitor *v, XBZRLECacheStats **obj, Error **errp)
{
    Error *err = NULL;

    visit_type_int(v, &(*obj)->cache_size, "cache-size", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->bytes, "bytes", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->pages, "pages", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->cache_miss, "cache-miss", &err);
    if (err) {
        goto out;
    }
    visit_type_number(v, &(*obj)->cache_miss_rate, "cache-miss-rate", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &(*obj)->overflow, "overflow", &err);
    if (err) {
        goto out;
    }

out:
    error_propagate(errp, err);
}

void visit_type_XBZRLECacheStats(Visitor *v, XBZRLECacheStats **obj, const char *name, Error **errp)
{
    Error *err = NULL;

    visit_start_struct(v, (void **)obj, "XBZRLECacheStats", name, sizeof(XBZRLECacheStats), &err);
    if (!err) {
        if (*obj) {
            visit_type_XBZRLECacheStats_fields(v, obj, errp);
        }
        visit_end_struct(v, &err);
    }
    error_propagate(errp, err);
}

void visit_type_anyList(Visitor *v, anyList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        anyList *native_i = (anyList *)i;
        visit_type_any(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_boolList(Visitor *v, boolList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        boolList *native_i = (boolList *)i;
        visit_type_bool(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_int16List(Visitor *v, int16List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        int16List *native_i = (int16List *)i;
        visit_type_int16(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_int32List(Visitor *v, int32List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        int32List *native_i = (int32List *)i;
        visit_type_int32(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_int64List(Visitor *v, int64List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        int64List *native_i = (int64List *)i;
        visit_type_int64(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_int8List(Visitor *v, int8List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        int8List *native_i = (int8List *)i;
        visit_type_int8(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_intList(Visitor *v, intList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        intList *native_i = (intList *)i;
        visit_type_int(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_numberList(Visitor *v, numberList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        numberList *native_i = (numberList *)i;
        visit_type_number(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_sizeList(Visitor *v, sizeList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        sizeList *native_i = (sizeList *)i;
        visit_type_size(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_strList(Visitor *v, strList **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        strList *native_i = (strList *)i;
        visit_type_str(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_uint16List(Visitor *v, uint16List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        uint16List *native_i = (uint16List *)i;
        visit_type_uint16(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_uint32List(Visitor *v, uint32List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        uint32List *native_i = (uint32List *)i;
        visit_type_uint32(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_uint64List(Visitor *v, uint64List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        uint64List *native_i = (uint64List *)i;
        visit_type_uint64(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

void visit_type_uint8List(Visitor *v, uint8List **obj, const char *name, Error **errp)
{
    Error *err = NULL;
    GenericList *i, **prev;

    visit_start_list(v, name, &err);
    if (err) {
        goto out;
    }

    for (prev = (GenericList **)obj;
         !err && (i = visit_next_list(v, prev, &err)) != NULL;
         prev = &i) {
        uint8List *native_i = (uint8List *)i;
        visit_type_uint8(v, &native_i->value, NULL, &err);
    }

    error_propagate(errp, err);
    err = NULL;
    visit_end_list(v, &err);
out:
    error_propagate(errp, err);
}

/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * schema-defined QAPI event functions
 *
 * Copyright (c) 2014 Wenchao Xia
 *
 * Authors:
 *  Wenchao Xia   <wenchaoqemu@gmail.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#include "qemu-common.h"
#include "qapi-event.h"
#include "qapi-visit.h"
#include "qapi/qmp-output-visitor.h"
#include "qapi/qmp-event.h"


void qapi_event_send_acpi_device_ost(ACPIOSTInfo *info, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("ACPI_DEVICE_OST");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "ACPI_DEVICE_OST", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_ACPIOSTInfo(v, &info, "info", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_ACPI_DEVICE_OST, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_balloon_change(int64_t actual, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BALLOON_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BALLOON_CHANGE", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &actual, "actual", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BALLOON_CHANGE, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_image_corrupted(const char *device, bool has_node_name, const char *node_name, const char *msg, bool has_offset, int64_t offset, bool has_size, int64_t size, bool fatal, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_IMAGE_CORRUPTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_IMAGE_CORRUPTED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    if (has_node_name) {
        visit_type_str(v, (char **)&node_name, "node-name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, (char **)&msg, "msg", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_offset, "offset", &err);
    if (err) {
        goto out;
    }
    if (has_offset) {
        visit_type_int(v, &offset, "offset", &err);
        if (err) {
            goto out;
        }
    }
    visit_optional(v, &has_size, "size", &err);
    if (err) {
        goto out;
    }
    if (has_size) {
        visit_type_int(v, &size, "size", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_bool(v, &fatal, "fatal", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_IMAGE_CORRUPTED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_io_error(const char *device, IoOperationType operation, BlockErrorAction action, bool has_nospace, bool nospace, const char *reason, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_IO_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_IO_ERROR", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_IoOperationType(v, &operation, "operation", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockErrorAction(v, &action, "action", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_nospace, "nospace", &err);
    if (err) {
        goto out;
    }
    if (has_nospace) {
        visit_type_bool(v, &nospace, "nospace", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, (char **)&reason, "reason", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_IO_ERROR, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_cancelled(BlockJobType type, const char *device, int64_t len, int64_t offset, int64_t speed, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_CANCELLED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_CANCELLED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_BlockJobType(v, &type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &len, "len", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &offset, "offset", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &speed, "speed", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_CANCELLED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_completed(BlockJobType type, const char *device, int64_t len, int64_t offset, int64_t speed, bool has_error, const char *error, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_COMPLETED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_COMPLETED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_BlockJobType(v, &type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &len, "len", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &offset, "offset", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &speed, "speed", &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_error, "error", &err);
    if (err) {
        goto out;
    }
    if (has_error) {
        visit_type_str(v, (char **)&error, "error", &err);
        if (err) {
            goto out;
        }
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_COMPLETED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_error(const char *device, IoOperationType operation, BlockErrorAction action, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_ERROR", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_IoOperationType(v, &operation, "operation", &err);
    if (err) {
        goto out;
    }
    visit_type_BlockErrorAction(v, &action, "action", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_ERROR, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_job_ready(BlockJobType type, const char *device, int64_t len, int64_t offset, int64_t speed, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_JOB_READY");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_JOB_READY", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_BlockJobType(v, &type, "type", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &len, "len", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &offset, "offset", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &speed, "speed", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_JOB_READY, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_block_write_threshold(const char *node_name, uint64_t amount_exceeded, uint64_t write_threshold, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("BLOCK_WRITE_THRESHOLD");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "BLOCK_WRITE_THRESHOLD", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, &amount_exceeded, "amount-exceeded", &err);
    if (err) {
        goto out;
    }
    visit_type_uint64(v, &write_threshold, "write-threshold", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_BLOCK_WRITE_THRESHOLD, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_device_deleted(bool has_device, const char *device, const char *path, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("DEVICE_DELETED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "DEVICE_DELETED", 0, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_device, "device", &err);
    if (err) {
        goto out;
    }
    if (has_device) {
        visit_type_str(v, (char **)&device, "device", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, (char **)&path, "path", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_DEVICE_DELETED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_device_tray_moved(const char *device, bool tray_open, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("DEVICE_TRAY_MOVED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "DEVICE_TRAY_MOVED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &tray_open, "tray-open", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_DEVICE_TRAY_MOVED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_guest_panicked(GuestPanicAction action, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("GUEST_PANICKED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "GUEST_PANICKED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_GuestPanicAction(v, &action, "action", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_GUEST_PANICKED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_mem_unplug_error(const char *device, const char *msg, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("MEM_UNPLUG_ERROR");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "MEM_UNPLUG_ERROR", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&device, "device", &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&msg, "msg", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_MEM_UNPLUG_ERROR, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_migration(MigrationStatus status, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("MIGRATION");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "MIGRATION", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_MigrationStatus(v, &status, "status", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_MIGRATION, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_nic_rx_filter_changed(bool has_name, const char *name, const char *path, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("NIC_RX_FILTER_CHANGED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "NIC_RX_FILTER_CHANGED", 0, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_name, "name", &err);
    if (err) {
        goto out;
    }
    if (has_name) {
        visit_type_str(v, (char **)&name, "name", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, (char **)&path, "path", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_NIC_RX_FILTER_CHANGED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_powerdown(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("POWERDOWN");

    emit(QAPI_EVENT_POWERDOWN, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_quorum_failure(const char *reference, int64_t sector_num, int64_t sectors_count, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("QUORUM_FAILURE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "QUORUM_FAILURE", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&reference, "reference", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &sector_num, "sector-num", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &sectors_count, "sectors-count", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_QUORUM_FAILURE, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_quorum_report_bad(bool has_error, const char *error, const char *node_name, int64_t sector_num, int64_t sectors_count, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("QUORUM_REPORT_BAD");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "QUORUM_REPORT_BAD", 0, &err);
    if (err) {
        goto out;
    }
    visit_optional(v, &has_error, "error", &err);
    if (err) {
        goto out;
    }
    if (has_error) {
        visit_type_str(v, (char **)&error, "error", &err);
        if (err) {
            goto out;
        }
    }
    visit_type_str(v, (char **)&node_name, "node-name", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &sector_num, "sector-num", &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &sectors_count, "sectors-count", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_QUORUM_REPORT_BAD, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_reset(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RESET");

    emit(QAPI_EVENT_RESET, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_resume(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RESUME");

    emit(QAPI_EVENT_RESUME, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_rtc_change(int64_t offset, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("RTC_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "RTC_CHANGE", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_int(v, &offset, "offset", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_RTC_CHANGE, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_shutdown(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SHUTDOWN");

    emit(QAPI_EVENT_SHUTDOWN, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_spice_connected(SpiceBasicInfo *server, SpiceBasicInfo *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_CONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_CONNECTED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceBasicInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceBasicInfo(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_CONNECTED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_spice_disconnected(SpiceBasicInfo *server, SpiceBasicInfo *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_DISCONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_DISCONNECTED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceBasicInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceBasicInfo(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_DISCONNECTED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_spice_initialized(SpiceServerInfo *server, SpiceChannel *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_INITIALIZED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "SPICE_INITIALIZED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceServerInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_SpiceChannel(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_SPICE_INITIALIZED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_spice_migrate_completed(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SPICE_MIGRATE_COMPLETED");

    emit(QAPI_EVENT_SPICE_MIGRATE_COMPLETED, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_stop(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("STOP");

    emit(QAPI_EVENT_STOP, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_suspend(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SUSPEND");

    emit(QAPI_EVENT_SUSPEND, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_suspend_disk(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("SUSPEND_DISK");

    emit(QAPI_EVENT_SUSPEND_DISK, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_connected(VncServerInfo *server, VncBasicInfo *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_CONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_CONNECTED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_VncServerInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_VncBasicInfo(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_CONNECTED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_disconnected(VncServerInfo *server, VncClientInfo *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_DISCONNECTED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_DISCONNECTED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_VncServerInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_VncClientInfo(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_DISCONNECTED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_vnc_initialized(VncServerInfo *server, VncClientInfo *client, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VNC_INITIALIZED");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VNC_INITIALIZED", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_VncServerInfo(v, &server, "server", &err);
    if (err) {
        goto out;
    }
    visit_type_VncClientInfo(v, &client, "client", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VNC_INITIALIZED, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_vserport_change(const char *id, bool open, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("VSERPORT_CHANGE");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "VSERPORT_CHANGE", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_str(v, (char **)&id, "id", &err);
    if (err) {
        goto out;
    }
    visit_type_bool(v, &open, "open", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_VSERPORT_CHANGE, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_wakeup(Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("WAKEUP");

    emit(QAPI_EVENT_WAKEUP, qmp, &err);

    error_propagate(errp, err);
    QDECREF(qmp);
}

void qapi_event_send_watchdog(WatchdogExpirationAction action, Error **errp)
{
    QDict *qmp;
    Error *err = NULL;
    QMPEventFuncEmit emit;
    QmpOutputVisitor *qov;
    Visitor *v;
    QObject *obj;

    emit = qmp_event_get_func_emit();
    if (!emit) {
        return;
    }

    qmp = qmp_event_build_dict("WATCHDOG");

    qov = qmp_output_visitor_new();
    g_assert(qov);

    v = qmp_output_get_visitor(qov);
    g_assert(v);

    /* Fake visit, as if all members are under a structure */
    visit_start_struct(v, NULL, "", "WATCHDOG", 0, &err);
    if (err) {
        goto out;
    }
    visit_type_WatchdogExpirationAction(v, &action, "action", &err);
    if (err) {
        goto out;
    }
    visit_end_struct(v, &err);
    if (err) {
        goto out;
    }

    obj = qmp_output_get_qobject(qov);
    g_assert(obj != NULL);

    qdict_put_obj(qmp, "data", obj);
    emit(QAPI_EVENT_WATCHDOG, qmp, &err);

out:
    qmp_output_visitor_cleanup(qov);
    error_propagate(errp, err);
    QDECREF(qmp);
}

const char *const QAPIEvent_lookup[] = {
    [QAPI_EVENT_ACPI_DEVICE_OST] = "ACPI_DEVICE_OST",
    [QAPI_EVENT_BALLOON_CHANGE] = "BALLOON_CHANGE",
    [QAPI_EVENT_BLOCK_IMAGE_CORRUPTED] = "BLOCK_IMAGE_CORRUPTED",
    [QAPI_EVENT_BLOCK_IO_ERROR] = "BLOCK_IO_ERROR",
    [QAPI_EVENT_BLOCK_JOB_CANCELLED] = "BLOCK_JOB_CANCELLED",
    [QAPI_EVENT_BLOCK_JOB_COMPLETED] = "BLOCK_JOB_COMPLETED",
    [QAPI_EVENT_BLOCK_JOB_ERROR] = "BLOCK_JOB_ERROR",
    [QAPI_EVENT_BLOCK_JOB_READY] = "BLOCK_JOB_READY",
    [QAPI_EVENT_BLOCK_WRITE_THRESHOLD] = "BLOCK_WRITE_THRESHOLD",
    [QAPI_EVENT_DEVICE_DELETED] = "DEVICE_DELETED",
    [QAPI_EVENT_DEVICE_TRAY_MOVED] = "DEVICE_TRAY_MOVED",
    [QAPI_EVENT_GUEST_PANICKED] = "GUEST_PANICKED",
    [QAPI_EVENT_MEM_UNPLUG_ERROR] = "MEM_UNPLUG_ERROR",
    [QAPI_EVENT_MIGRATION] = "MIGRATION",
    [QAPI_EVENT_NIC_RX_FILTER_CHANGED] = "NIC_RX_FILTER_CHANGED",
    [QAPI_EVENT_POWERDOWN] = "POWERDOWN",
    [QAPI_EVENT_QUORUM_FAILURE] = "QUORUM_FAILURE",
    [QAPI_EVENT_QUORUM_REPORT_BAD] = "QUORUM_REPORT_BAD",
    [QAPI_EVENT_RESET] = "RESET",
    [QAPI_EVENT_RESUME] = "RESUME",
    [QAPI_EVENT_RTC_CHANGE] = "RTC_CHANGE",
    [QAPI_EVENT_SHUTDOWN] = "SHUTDOWN",
    [QAPI_EVENT_SPICE_CONNECTED] = "SPICE_CONNECTED",
    [QAPI_EVENT_SPICE_DISCONNECTED] = "SPICE_DISCONNECTED",
    [QAPI_EVENT_SPICE_INITIALIZED] = "SPICE_INITIALIZED",
    [QAPI_EVENT_SPICE_MIGRATE_COMPLETED] = "SPICE_MIGRATE_COMPLETED",
    [QAPI_EVENT_STOP] = "STOP",
    [QAPI_EVENT_SUSPEND] = "SUSPEND",
    [QAPI_EVENT_SUSPEND_DISK] = "SUSPEND_DISK",
    [QAPI_EVENT_VNC_CONNECTED] = "VNC_CONNECTED",
    [QAPI_EVENT_VNC_DISCONNECTED] = "VNC_DISCONNECTED",
    [QAPI_EVENT_VNC_INITIALIZED] = "VNC_INITIALIZED",
    [QAPI_EVENT_VSERPORT_CHANGE] = "VSERPORT_CHANGE",
    [QAPI_EVENT_WAKEUP] = "WAKEUP",
    [QAPI_EVENT_WATCHDOG] = "WATCHDOG",
    [QAPI_EVENT_MAX] = NULL,
};

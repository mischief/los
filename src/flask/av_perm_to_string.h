/* This file is automatically generated.  Do not edit. */
/* FLASK */

typedef struct
{
    oskit_security_class_t tclass;
    oskit_access_vector_t value;
    char *name;
} av_perm_to_string_t;

static av_perm_to_string_t av_perm_to_string[] = {
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__MOUNT, "mount" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__REMOUNT, "remount" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__UNMOUNT, "unmount" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__GETATTR, "getattr" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__RELABELFROM, "relabelfrom" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__RELABELTO, "relabelto" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__TRANSITION, "transition" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__ASSOCIATE, "associate" },
   { OSKIT_SECCLASS_FILESYSTEM, OSKIT_PERM_FILESYSTEM__LOOKUPI, "lookupi" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__ADD_NAME, "add_name" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__REMOVE_NAME, "remove_name" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__REPARENT, "reparent" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__SEARCH, "search" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__RMDIR, "rmdir" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__MOUNTON, "mounton" },
   { OSKIT_SECCLASS_DIR, OSKIT_PERM_DIR__MOUNTASSOCIATE, "mountassociate" },
   { OSKIT_SECCLASS_FD, OSKIT_PERM_FD__CREATE, "create" },
   { OSKIT_SECCLASS_FD, OSKIT_PERM_FD__GETATTR, "getattr" },
   { OSKIT_SECCLASS_FD, OSKIT_PERM_FD__SETATTR, "setattr" },
   { OSKIT_SECCLASS_FD, OSKIT_PERM_FD__INHERIT, "inherit" },
   { OSKIT_SECCLASS_FD, OSKIT_PERM_FD__RECEIVE, "receive" },
   { OSKIT_SECCLASS_TCP_SOCKET, OSKIT_PERM_TCP_SOCKET__CONNECTTO, "connectto" },
   { OSKIT_SECCLASS_TCP_SOCKET, OSKIT_PERM_TCP_SOCKET__LISTEN, "listen" },
   { OSKIT_SECCLASS_TCP_SOCKET, OSKIT_PERM_TCP_SOCKET__ACCEPT, "accept" },
   { OSKIT_SECCLASS_TCP_SOCKET, OSKIT_PERM_TCP_SOCKET__NEWCONN, "newconn" },
   { OSKIT_SECCLASS_TCP_SOCKET, OSKIT_PERM_TCP_SOCKET__ACCEPTFROM, "acceptfrom" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__TCP_RECV, "tcp_recv" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__TCP_SEND, "tcp_send" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__UDP_RECV, "udp_recv" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__UDP_SEND, "udp_send" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__RAWIP_RECV, "rawip_recv" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__RAWIP_SEND, "rawip_send" },
   { OSKIT_SECCLASS_NODE, OSKIT_PERM_NODE__ENFORCE_DEST, "enforce_dest" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__GETATTR, "getattr" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__SETATTR, "setattr" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__TCP_RECV, "tcp_recv" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__TCP_SEND, "tcp_send" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__UDP_RECV, "udp_recv" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__UDP_SEND, "udp_send" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__RAWIP_RECV, "rawip_recv" },
   { OSKIT_SECCLASS_NETIF, OSKIT_PERM_NETIF__RAWIP_SEND, "rawip_send" },
   { OSKIT_SECCLASS_UNIX_STREAM_SOCKET, OSKIT_PERM_UNIX_STREAM_SOCKET__CONNECTTO, "connectto" },
   { OSKIT_SECCLASS_UNIX_STREAM_SOCKET, OSKIT_PERM_UNIX_STREAM_SOCKET__LISTEN, "listen" },
   { OSKIT_SECCLASS_UNIX_STREAM_SOCKET, OSKIT_PERM_UNIX_STREAM_SOCKET__ACCEPT, "accept" },
   { OSKIT_SECCLASS_UNIX_STREAM_SOCKET, OSKIT_PERM_UNIX_STREAM_SOCKET__NEWCONN, "newconn" },
   { OSKIT_SECCLASS_UNIX_STREAM_SOCKET, OSKIT_PERM_UNIX_STREAM_SOCKET__ACCEPTFROM, "acceptfrom" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__EXECUTE, "execute" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__FORK, "fork" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__TRANSITION, "transition" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__SIGKILL, "sigkill" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__SIGSTOP, "sigstop" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__SIGNAL, "signal" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__CHROOT, "chroot" },
   { OSKIT_SECCLASS_PROCESS, OSKIT_PERM_PROCESS__SETID, "setid" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__COMPUTE_AV, "compute_av" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__NOTIFY_PERM, "notify_perm" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__TRANSITION_SID, "transition_sid" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__MEMBER_SID, "member_sid" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__SID_TO_CONTEXT, "sid_to_context" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__CONTEXT_TO_SID, "context_to_sid" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__LOAD_POLICY, "load_policy" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__GET_SIDS, "get_sids" },
   { OSKIT_SECCLASS_SECURITY, OSKIT_PERM_SECURITY__REGISTER_AVC, "register_avc" },
   { OSKIT_SECCLASS_SYSTEM, OSKIT_PERM_SYSTEM__REBOOT, "reboot" },
   { OSKIT_SECCLASS_SYSTEM, OSKIT_PERM_SYSTEM__NET_IO_CONTROL, "net_io_control" },
   { OSKIT_SECCLASS_SYSTEM, OSKIT_PERM_SYSTEM__ROUTE_CONTROL, "route_control" },
   { OSKIT_SECCLASS_SYSTEM, OSKIT_PERM_SYSTEM__ARP_CONTROL, "arp_control" },
   { OSKIT_SECCLASS_SYSTEM, OSKIT_PERM_SYSTEM__RARP_CONTROL, "rarp_control" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__READ, "read" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__WRITE, "write" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__EXECUTE, "execute" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__CREATE_OBJECT, "create_object" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__SPECIFY_CLIENT, "specify_client" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__SPECIFY_SERVER, "specify_server" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__CONNECT, "connect" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__CALL, "call" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__SEND, "send" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__THREAD_SCHEDULER, "thread_scheduler" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__TASK_KEEPER, "task_keeper" },
   { OSKIT_SECCLASS_SUBJECT, OSKIT_PERM_SUBJECT__MAP, "map" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__GRANT, "grant" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__TRY_REVOKE, "try_revoke" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__REVOKE, "revoke" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__RESET, "reset" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__SET_AUDITALLOW, "set_auditallow" },
   { OSKIT_SECCLASS_AVC, OSKIT_PERM_AVC__SET_AUDITDENY, "set_auditdeny" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_CREATE, "segment_create" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_DESTROY, "segment_destroy" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_MAP, "segment_map" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_GETSIZE, "segment_getsize" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_SETSIZE, "segment_setsize" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_CREATECOPY, "segment_createcopy" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_CREATE, "mempool_create" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_DESTROY, "mempool_destroy" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_ADDSUBPOOL, "mempool_addsubpool" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_ADDSEGMENT, "mempool_addsegment" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_GETTICKETS, "mempool_gettickets" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__MEMPOOL_SETTICKETS, "mempool_settickets" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SEGMENT_ASSOCIATE, "segment_associate" },
   { OSKIT_SECCLASS_MEMORY, OSKIT_PERM_MEMORY__SUBPOOL_ASSOCIATE, "subpool_associate" },
};

#define AV_PERM_TO_STRING_SIZE (sizeof(av_perm_to_string)/sizeof(av_perm_to_string_t))


/* FLASK */

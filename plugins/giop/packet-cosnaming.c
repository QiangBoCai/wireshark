/* packet-cosnaming.c
 * Routines for IDL dissection
 *
 * Autogenerated from idl2eth
 * Copyright 2001 Frank Singleton <frank.singleton@ericsson.com>
 */


/*
 * Ethereal - Network traffic analyzer
 * By Gerald Combs
 * Copyright 1999 Gerald Combs
 */


/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */


#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "plugins/plugin_api.h"

#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

#include <string.h>
#include <glib.h>
#include <epan/packet.h>
#include <epan/proto.h>
#include "packet-giop.h"

#include "plugins/plugin_api_defs.h"

#ifndef ENABLE_STATIC
G_MODULE_EXPORT const gchar version[] = "0.0.1";
#endif



/* Struct prototype declaration Start */




/* Struct = IDL:omg.org/CosNaming/NameComponent:1.0 */

static void decode_CosNaming_NameComponent_st(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset, MessageHeader *header, gchar *operation);




/* Struct = IDL:omg.org/CosNaming/Binding:1.0 */

static void decode_CosNaming_Binding_st(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset, MessageHeader *header, gchar *operation);



/* Struct prototype declaration End */



/* Union prototype declaration Start */



/* Union prototype declaration End */



/* Initialise the protocol and subtree pointers */

static int proto_cosnaming = -1;

static gint ett_cosnaming = -1;



/* Initialise the initial Alignment */

static guint32  boundary = GIOP_HEADER_SIZE;  /* initial value */




/* Initialise the Registered fields */

/* TODO - Use registered fields */


/*
 * IDL Operations Start
 */


static const char CosNaming_NamingContext_bind_op[] = "bind" ;
static const char CosNaming_NamingContext_rebind_op[] = "rebind" ;
static const char CosNaming_NamingContext_bind_context_op[] = "bind_context" ;
static const char CosNaming_NamingContext_rebind_context_op[] = "rebind_context" ;
static const char CosNaming_NamingContext_resolve_op[] = "resolve" ;
static const char CosNaming_NamingContext_unbind_op[] = "unbind" ;
static const char CosNaming_NamingContext_new_context_op[] = "new_context" ;
static const char CosNaming_NamingContext_bind_new_context_op[] = "bind_new_context" ;
static const char CosNaming_NamingContext_destroy_op[] = "destroy" ;
static const char CosNaming_NamingContext_list_op[] = "list" ;
static const char CosNaming_BindingIterator_next_one_op[] = "next_one" ;
static const char CosNaming_BindingIterator_next_n_op[] = "next_n" ;
static const char CosNaming_BindingIterator_destroy_op[] = "destroy" ;

/*
 * IDL Operations End
 */


/*  Begin Exception (containing members) String  Declare  */


static const char user_exception_CosNaming_NamingContext_NotFound[] = "IDL:omg.org/CosNaming/NamingContext/NotFound:1.0" ;
static const char user_exception_CosNaming_NamingContext_CannotProceed[] = "IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0" ;

/*  End Exception (containing members) String Declare  */


/*
 * IDL Attributes Start
 */



/*
 * IDL Attributes End
 */


/*
 * IDL Enums Start
 */


/*
 * Enum = IDL:omg.org/CosNaming/BindingType:1.0
 */


static const value_string CosNaming_BindingType[] = {

   { 0, "nobject" },
   { 1, "ncontext" },
   { 0,       NULL },
};


/*
 * Enum = IDL:omg.org/CosNaming/NamingContext/NotFoundReason:1.0
 */


static const value_string CosNaming_NamingContext_NotFoundReason[] = {

   { 0, "missing_node" },
   { 1, "not_context" },
   { 2, "not_object" },
   { 0,       NULL },
};


/*
 * IDL Enums End
 */


/*  Begin Exception Helper Functions  */



/* Exception = IDL:omg.org/CosNaming/NamingContext/NotFound:1.0 */

static void decode_ex_CosNaming_NamingContext_NotFound(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4;
    guint32   u_octet4_loop_NotFound_rest_of_name;
    guint32   i_NotFound_rest_of_name;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);  /* get stream endianess */



    u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4,4,"Enum value = %u (%s)",u_octet4,val_to_str(u_octet4,CosNaming_NamingContext_NotFoundReason,"Unknown Enum Value"));
    }

    u_octet4_loop_NotFound_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of NotFound_rest_of_name = %u",u_octet4_loop_NotFound_rest_of_name);
    }

    for (i_NotFound_rest_of_name=0; i_NotFound_rest_of_name < u_octet4_loop_NotFound_rest_of_name; i_NotFound_rest_of_name++) {

        /*  Begin struct "CosNaming_NameComponent"  */



        decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


        /*  End struct "CosNaming_NameComponent"  */

    }

}


/* Exception = IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0 */

static void decode_ex_CosNaming_NamingContext_CannotProceed(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_CannotProceed_rest_of_name;
    guint32   i_CannotProceed_rest_of_name;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);  /* get stream endianess */


    get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


    u_octet4_loop_CannotProceed_rest_of_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of CannotProceed_rest_of_name = %u",u_octet4_loop_CannotProceed_rest_of_name);
    }

    for (i_CannotProceed_rest_of_name=0; i_CannotProceed_rest_of_name < u_octet4_loop_CannotProceed_rest_of_name; i_CannotProceed_rest_of_name++) {

        /*  Begin struct "CosNaming_NameComponent"  */



        decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


        /*  End struct "CosNaming_NameComponent"  */

    }

}


/*  End Exception Helper Functions  */



/*
 * Main delegator for exception handling
 *
 */

static gboolean decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header _U_, gchar *operation _U_ ) {

    /*gboolean be _U_;*/                        /* big endianess */



    if (!strcmp(header->exception_id, user_exception_CosNaming_NamingContext_NotFound )) {
       decode_ex_CosNaming_NamingContext_NotFound(tvb, pinfo, tree, offset, header, operation);   /*  IDL:omg.org/CosNaming/NamingContext/NotFound:1.0  */
       return TRUE;
    }


    if (!strcmp(header->exception_id, user_exception_CosNaming_NamingContext_CannotProceed )) {
       decode_ex_CosNaming_NamingContext_CannotProceed(tvb, pinfo, tree, offset, header, operation);   /*  IDL:omg.org/CosNaming/NamingContext/CannotProceed:1.0  */
       return TRUE;
    }




    return FALSE;    /* user exception not found */

}


/*  Begin Attribute Helper Functions  */



/*  End Attribute Helper Functions  */



/*
 * IDL:omg.org/CosNaming/NamingContext/bind:1.0
 */


static void decode_CosNaming_NamingContext_bind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/rebind:1.0
 */


static void decode_CosNaming_NamingContext_rebind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/bind_context:1.0
 */


static void decode_CosNaming_NamingContext_bind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/rebind_context:1.0
 */


static void decode_CosNaming_NamingContext_rebind_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/resolve:1.0
 */


static void decode_CosNaming_NamingContext_resolve(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:

            get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/unbind:1.0
 */


static void decode_CosNaming_NamingContext_unbind(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/new_context:1.0
 */


static void decode_CosNaming_NamingContext_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */


    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:

            get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/bind_new_context:1.0
 */


static void decode_CosNaming_NamingContext_bind_new_context(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_n;
    guint32   i_n;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4_loop_n = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of n = %u",u_octet4_loop_n);
        }

        for (i_n=0; i_n < u_octet4_loop_n; i_n++) {

            /*  Begin struct "CosNaming_NameComponent"  */



            decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_NameComponent"  */

        }

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:

            get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/destroy:1.0
 */


static void decode_CosNaming_NamingContext_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */


    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/NamingContext/list:1.0
 */


static void decode_CosNaming_NamingContext_list(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4;
    guint32   u_octet4_loop_bl;
    guint32   i_bl;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4 = get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4,4,"how_many = %u",u_octet4);
        }

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            u_octet4_loop_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
            if (tree) {
               proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of bl = %u",u_octet4_loop_bl);
            }

            for (i_bl=0; i_bl < u_octet4_loop_bl; i_bl++) {

                /*  Begin struct "CosNaming_Binding"  */



                decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation);


                /*  End struct "CosNaming_Binding"  */

            }

            get_CDR_object(tvb, pinfo, tree, offset, stream_is_big_endian, boundary);


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/BindingIterator/next_one:1.0
 */


static void decode_CosNaming_BindingIterator_next_one(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint8    u_octet1;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:

            u_octet1 = get_CDR_boolean(tvb,offset);
            if (tree) {
               proto_tree_add_text(tree,tvb,*offset-1,1,"Operation_Return_Value = %u",u_octet1);
            }

            /*  Begin struct "CosNaming_Binding"  */



            decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation);


            /*  End struct "CosNaming_Binding"  */

            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/BindingIterator/next_n:1.0
 */


static void decode_CosNaming_BindingIterator_next_n(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4;
    guint8    u_octet1;
    guint32   u_octet4_loop_bl;
    guint32   i_bl;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        u_octet4 = get_CDR_ulong(tvb,offset,stream_is_big_endian, boundary);
        if (tree) {
           proto_tree_add_text(tree,tvb,*offset-4,4,"how_many = %u",u_octet4);
        }

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:

            u_octet1 = get_CDR_boolean(tvb,offset);
            if (tree) {
               proto_tree_add_text(tree,tvb,*offset-1,1,"Operation_Return_Value = %u",u_octet1);
            }

            u_octet4_loop_bl = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
            if (tree) {
               proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of bl = %u",u_octet4_loop_bl);
            }

            for (i_bl=0; i_bl < u_octet4_loop_bl; i_bl++) {

                /*  Begin struct "CosNaming_Binding"  */



                decode_CosNaming_Binding_st(tvb, pinfo, tree, offset, header, operation);


                /*  End struct "CosNaming_Binding"  */

            }

            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/*
 * IDL:omg.org/CosNaming/BindingIterator/destroy:1.0
 */


static void decode_CosNaming_BindingIterator_destroy(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */


    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);

    switch(header->message_type) {

    case Request:

        break;

    case Reply:

        switch(header->rep_status) {

        case NO_EXCEPTION:


            /* Function returns void */


            break;

        case USER_EXCEPTION:

            break;

        default:

            /* Unknown Exception */

            g_warning("Unknown Exception ");



            break;


        }   /* switch(header->message_type) */

        break;

    default:

        /* Unknown GIOP Message */

        g_warning("Unknown GIOP Message");


        break;


    } /* switch(header->message_type) */

}


/* Struct = IDL:omg.org/CosNaming/NameComponent:1.0 */

static void decode_CosNaming_NameComponent_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4;
    gchar   *seq = NULL;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);  /* get stream endianess */


    u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4-u_octet4,4,"length = %u",u_octet4);
       if (u_octet4 > 0)
          proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"NameComponent_id = %s",seq);

    }

    g_free(seq);          /*  free buffer  */
    seq = NULL;

    u_octet4 = get_CDR_string(tvb, &seq, offset, stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4-u_octet4,4,"length = %u",u_octet4);
       if (u_octet4 > 0)
          proto_tree_add_text(tree,tvb,*offset-u_octet4,u_octet4,"NameComponent_kind = %s",seq);

    }

    g_free(seq);          /*  free buffer  */
    seq = NULL;

}


/* Struct = IDL:omg.org/CosNaming/Binding:1.0 */

static void decode_CosNaming_Binding_st(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, int *offset _U_, MessageHeader *header, gchar *operation _U_) {

    gboolean stream_is_big_endian;          /* big endianess */


    /* Operation specific Variable declarations Begin */

    guint32   u_octet4_loop_Binding_binding_name;
    guint32   i_Binding_binding_name;
    guint32   u_octet4;

    /* Operation specific Variable declarations End */


    stream_is_big_endian = is_big_endian(header);  /* get stream endianess */


    u_octet4_loop_Binding_binding_name = get_CDR_ulong(tvb, offset, stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4, 4 ,"Seq length of Binding_binding_name = %u",u_octet4_loop_Binding_binding_name);
    }

    for (i_Binding_binding_name=0; i_Binding_binding_name < u_octet4_loop_Binding_binding_name; i_Binding_binding_name++) {

        /*  Begin struct "CosNaming_NameComponent"  */



        decode_CosNaming_NameComponent_st(tvb, pinfo, tree, offset, header, operation);


        /*  End struct "CosNaming_NameComponent"  */

    }


    u_octet4 = get_CDR_enum(tvb,offset,stream_is_big_endian, boundary);
    if (tree) {
       proto_tree_add_text(tree,tvb,*offset-4,4,"Enum value = %u (%s)",u_octet4,val_to_str(u_octet4,CosNaming_BindingType,"Unknown Enum Value"));
    }

}

static gboolean dissect_cosnaming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, gchar *operation, gchar *idlname _U_) {

    proto_item *ti = NULL;
    proto_tree *tree = NULL;            /* init later, inside if(tree) */

    gboolean be;                        /* big endianess */

    if (check_col(pinfo->cinfo, COL_PROTOCOL))
       col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSNAMING");

/*
 * Do not clear COL_INFO, as nothing is being written there by
 * this dissector yet. So leave it as is from the GIOP dissector.
 * TODO: add something useful to COL_INFO
 *  if (check_col(pinfo->cinfo, COL_INFO))
 *     col_clear(pinfo->cinfo, COL_INFO);
 */

    if (ptree) {
       ti = proto_tree_add_item(ptree, proto_cosnaming, tvb, *offset, tvb_length(tvb) - *offset, FALSE);
       tree = proto_item_add_subtree(ti, ett_cosnaming);
    }


    be = is_big_endian(header);         /* get endianess - TODO use passed in stream_is_big_endian instead ? */

    /* If we have a USER Exception, then decode it and return */

    if ((header->message_type == Reply) && (header->rep_status == USER_EXCEPTION)) {

       return decode_user_exception(tvb, pinfo, tree, offset, header, operation);

    }



    switch(header->message_type) {

    case Request:
    case Reply:


        if (!strcmp(operation, CosNaming_NamingContext_bind_op )) {
           decode_CosNaming_NamingContext_bind(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_rebind_op )) {
           decode_CosNaming_NamingContext_rebind(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_bind_context_op )) {
           decode_CosNaming_NamingContext_bind_context(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_rebind_context_op )) {
           decode_CosNaming_NamingContext_rebind_context(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_resolve_op )) {
           decode_CosNaming_NamingContext_resolve(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_unbind_op )) {
           decode_CosNaming_NamingContext_unbind(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_new_context_op )) {
           decode_CosNaming_NamingContext_new_context(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_bind_new_context_op )) {
           decode_CosNaming_NamingContext_bind_new_context(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_destroy_op )) {
           decode_CosNaming_NamingContext_destroy(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_NamingContext_list_op )) {
           decode_CosNaming_NamingContext_list(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_BindingIterator_next_one_op )) {
           decode_CosNaming_BindingIterator_next_one(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_BindingIterator_next_n_op )) {
           decode_CosNaming_BindingIterator_next_n(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }

        if (!strcmp(operation, CosNaming_BindingIterator_destroy_op )) {
           decode_CosNaming_BindingIterator_destroy(tvb, pinfo, tree, offset, header, operation);
           return TRUE;
        }


        break;

    case CancelRequest:
    case LocateRequest:
    case LocateReply:
    case CloseConnection:
    case MessageError:
    case Fragment:
       return FALSE;      /* not handled yet */

    default:
       return FALSE;      /* not handled yet */

    }   /* switch */



    return FALSE;

}  /* End of main dissector  */




/* Register the protocol with Ethereal */

void proto_register_giop_cosnaming(void) {

   /* setup list of header fields */

#if 0
   static hf_register_info hf[] = {

      /* no fields yet */

   };
#endif

   /* setup protocol subtree array */

   static gint *ett[] = {
      &ett_cosnaming,
   };

   /* Register the protocol name and description */

   proto_cosnaming = proto_register_protocol("Cosnaming Dissector Using GIOP API" , "COSNAMING", "giop-cosnaming" );

#if 0
   proto_register_field_array(proto_cosnaming, hf, array_length(hf));
#endif
   proto_register_subtree_array(ett,array_length(ett));

}




/* register me as handler for these interfaces */

void proto_register_handoff_giop_cosnaming(void) {



    #if 0

    /* Register for Explicit Dissection */

    register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/NamingContext", proto_cosnaming );     /* explicit dissector */

    #endif



    #if 0

    /* Register for Explicit Dissection */

    register_giop_user_module(dissect_cosnaming, "COSNAMING", "CosNaming/BindingIterator", proto_cosnaming );     /* explicit dissector */

    #endif




    /* Register for Heuristic Dissection */

    register_giop_user(dissect_cosnaming, "COSNAMING" ,proto_cosnaming);     /* heuristic dissector */



}



#ifndef ENABLE_STATIC

G_MODULE_EXPORT void
plugin_reg_handoff(void){
   proto_register_handoff_giop_cosnaming();
}

G_MODULE_EXPORT void
plugin_init(plugin_address_table_t *pat
#ifndef PLUGINS_NEED_ADDRESS_TABLE
_U_
#endif
){
   /* initialise the table of pointers needed in Win32 DLLs */
   plugin_address_table_init(pat);
   if (proto_cosnaming == -1) {
     proto_register_giop_cosnaming();
   }
}

#endif



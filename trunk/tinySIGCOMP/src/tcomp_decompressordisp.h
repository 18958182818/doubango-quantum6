/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tcomp_decompressordisp.h
 * @brief  Entity that receives SigComp messages, invokes a UDVM, and forwards the resulting decompressed messages to the application.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TCOMP_DECOMPRESSORDISP_H
#define TCOMP_DECOMPRESSORDISP_H

#include "tinysigcomp_config.h"
#include "tcomp_statehandler.h"
#include "tcomp_buffer.h"
#include "tcomp_types.h"
#include "tcomp_result.h"


#include "tsk_object.h"
#include "tsk_safeobj.h"

TCOMP_BEGIN_DECLS

#define TCOMP_STREAM_BUFFER_CREATE(id)					tsk_object_new(tcomp_stream_buffer_def_t, (uint64_t)id)

#define TCOMP_DECOMPRESSORDISP_CREATE(statehandler)		tsk_object_new(tcomp_decompressordisp_def_t, (const tcomp_statehandler_t*)statehandler)

typedef struct tcomp_stream_buffer_s
{
	TSK_DECLARE_OBJECT;

	uint64_t	id;						/**< Buffer identifier */
	tcomp_buffer_handle_t *buffer;		/**< Buffer handle */

	TSK_DECLARE_SAFEOBJ;
}
tcomp_stream_buffer_t;

typedef struct tcomp_decompressordisp_s
{
	TSK_DECLARE_OBJECT;

	const tcomp_statehandler_t* stateHandler;
	tcomp_stream_buffer_L_t *streamBuffers;

	TSK_DECLARE_SAFEOBJ;
}
tcomp_decompressordisp_t;

tsk_bool_t tcomp_decompressordisp_decompress(tcomp_decompressordisp_t *dispatcher, const void* input_ptr, size_t input_size, tcomp_result_t *lpResult);
tsk_bool_t tcomp_decompressordisp_getNextMessage(tcomp_decompressordisp_t *dispatcher, tcomp_result_t *lpResult);

tsk_bool_t tcomp_decompressordisp_internalDecompress(tcomp_decompressordisp_t *dispatcher, const void* input_ptr, const size_t input_size, tcomp_result_t **lpResult);
tsk_bool_t tcomp_decompressordisp_appendStream(tcomp_decompressordisp_t *dispatcher, const void* input_ptr, size_t input_size, uint64_t streamId);
tsk_bool_t tcomp_decompressordisp_getNextStreamMsg(tcomp_decompressordisp_t *dispatcher, uint64_t streamId, uint16_t *discard_count, size_t *size);

TINYSIGCOMP_GEXTERN const tsk_object_def_t *tcomp_stream_buffer_def_t;
TINYSIGCOMP_GEXTERN const tsk_object_def_t *tcomp_decompressordisp_def_t;

TCOMP_END_DECLS

#endif /*TCOMP_DECOMPRESSORDISP_H*/

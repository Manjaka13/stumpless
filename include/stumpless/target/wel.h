/* SPDX-License-Identifier: Apache-2.0 */

/*
 * Copyright 2018 Joel E. Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file
 * Functions for working with Windows Event Log targets.
 *
 * This header will not be available in builds where Windows Event Log targets
 * are not supported.
 */

#ifndef __STUMPLESS_TARGET_WEL_H
#  define __STUMPLESS_TARGET_WEL_H

#  include <stumpless/target.h>

#  ifdef __cplusplus
extern "C" {
#  endif

/**
 * Closes a Windows Event Log target.
 *
 * In addition to closing the target, this function also destroys all memory
 * allocated for the target, including the target struct itself.
 *
 * If there is a problem closing the target, then an error code will be set
 * appropriately.
 *
 * @param target The Windows Event Log target to close.
 */
void
stumpless_close_wel_target( struct stumpless_target *target );

/**
 * Opens a Windows Event Log target on the local machine.
 *
 * @param name The name of the target to open. This should match the name of the
 * Windows Event Source that the logs will be added to.
 *
 * @param options The options to use for the logging target. This is a bit-wise
 * or of one or more \c STUMPLESS_OPTION values.
 *
 * @return The opened target if no error is encountered. In the event of an
 * error, NULL is returned and an error code is set appropriately.
 */
struct stumpless_target *
stumpless_open_local_wel_target( const char *name,
                                 int options );

/**
 * Opens a Windows Event Log target on a remote machine.
 *
 * @param server The remote server to log to. This should use the Universal
 * Naming Convention (UNC) of the remote end. If this parameter is set to NULL,
 * then the local machine is used. This is equivalent to a call to
 * stumpless_open_local_wel_target().
 *
 * @param name The name of the target to open. This should match the name of the
 * Windows Event Source that the logs will be added to.
 *
 * @param options The options to use for the logging target. This is a bit-wise
 * or of one or more \c STUMPLESS_OPTION values.
 *
 * @return The opened target if no error is encountered. In the event of an
 * error, NULL is returned and an error code is set appropriately.
 */
struct stumpless_target *
stumpless_open_remote_wel_target( const char *server,
                                  const char *name,
                                  int options );

#  ifdef __cplusplus
}                               /* extern "C" */
#  endif
#endif                          /* __STUMPLESS_TARGET_WEL_H */

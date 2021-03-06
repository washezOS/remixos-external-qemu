/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

/*
 * Encapsulates exchange protocol between the sensor emulator, and an application
 * running on an Android device that provides sensor values, and is connected to
 * the host via USB.
 */

/* Declares sensors port descriptor. */
typedef struct AndroidSensorsPort AndroidSensorsPort;

/* Creates sensors port, and connects it to the device.
 * Param:
 *  opaque - An opaque pointer that is passed back to the callback routines.
 * Return:
 *  Initialized device descriptor on success, or NULL on failure. If failure is
 *  returned from this routine, 'errno' indicates the reason for failure. If this
 *  routine successeds, a connection is established with the sensor reading
 *  application on the device.
 */
extern AndroidSensorsPort* sensors_port_create(void* opaque);

/* Disconnects from the sensors port, and destroys the descriptor. */
extern void sensors_port_destroy(AndroidSensorsPort* asp);

/* Enables events from a particular sensor.
 * Param:
 *  asp - Android sensors port instance returned from sensors_port_create.
 *  name - Name of the sensor to enable events on. If this parameter is "all",
 *      then events on all sensors will be enabled.
 * Return:
 *  Zero on success, failure otherwise.
 */
extern int sensors_port_enable_sensor(AndroidSensorsPort* asp, const char* name);


/* Disables events from a particular sensor.
 * Param:
 *  asp - Android sensors port instance returned from sensors_port_create.
 *  name - Name of the sensor to disable events on. If this parameter is "all",
 *      then events on all sensors will be disable.
 * Return:
 *  Zero on success, failure otherwise.
 */
extern int sensors_port_disable_sensor(AndroidSensorsPort* asp, const char* name);

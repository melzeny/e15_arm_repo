                                                                                        /*
 * global_interrupt.h
 *
 *  Created on: May 22, 2019
 *      Author: Yasmin.Elmahdy
 */

#ifndef SRC_DEVICE_DRIVER_GLOBAL_INTERRUPT_H_
#define SRC_DEVICE_DRIVER_GLOBAL_INTERRUPT_H_

#define GI_ENABLE()             __asm("    mrs     r0, PRIMASK\n"\
                                      "    cpsie   i\n"\
                                      "    bx      lr\n")


#define GI_DISABLE()            __asm("    mrs     r0, PRIMASK\n"\
                                      "    cpsid   i\n"\
                                      "    bx      lr\n")

#endif /* SRC_DEVICE_DRIVER_GLOBAL_INTERRUPT_H_ */

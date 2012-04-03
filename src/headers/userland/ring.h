/* 
 * File:   ring.h
 * Author: caos
 *
 * This header provides an interface for the operating system to switch ring from kernel to user (3) 
 * or drivers/servers (2).
 * 
 * The separation between ring allow the kernel to load in a secure way executable, without being exploitable 
 * by a malicious executable.
 * 
 * NO syscalls should be introduced here!
 */

#ifndef RING_H
#define	RING_H

/*
 * Defines to ring target for each part:
 *      KERNEL_RING has the highest privilege level
 *      SERVER_RING defines a "middle" level
 *      USER_RING define the real mode in where users execute their applications
 */

#define KERNEL_RING 0x0
#define SERVER_RING 0x1
#define USER_RING 0x3

/*
 * Now some macro to define our code and data selectors 
 */
#define CODE_SELECTOR(l) (0x18 | l)
#define DATA_SELECTOR(l) (0x20 | l)   

/*
 * This function witch to the specified ring the execution for the processor
 * Doesn't return any value and it's all about inline-assembly
 * 
 * CHECK: every task switch with different ring-level should switch? Overhead?
 */
void switch_ring(unsigned short level);

#endif	/* RING_H */


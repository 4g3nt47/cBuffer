/**
 *-------------------------
 * Header file for cBuffer.
 *       Author: Umar Abdul
 *-------------------------
 */

#ifndef CBUFFER_H
#define CBUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The buffer struct
typedef struct{
  void *buffer; // The buffer itself.
  size_t size; // The size of the buffer.
  size_t used; // The number of bytes in use.
} buffer;

/**
 * Create a new buffer of `size` bytes, and initialize all it's bytes to null.
 * If `size` is zero, the call to malloc() will use 1 to still allocate some memory but buffer.size
 * and buffer.used will be kept at 0.
 */
buffer *create_buffer(size_t size);

// Resize a buffer. It DOES NOT change the `used` property unless the `new_size` is less than it.
void resize_buffer(buffer *buff, size_t new_size);

/**
 * Append a max of `len` bytes from `src` to `dest` buffer.
 * Note: resize_buffer() will be used to resize the dest buffer if not enough space is available.
 * Returns the number of bytes appended.
 */
size_t append_buffer(buffer *dest, const void *src, size_t len);
/**
 * Empty `dest` buffer and copy the contents of null-terminated `src` as it's new value.
 * It DOES NOT null-terminate the `dest` buffer.
 */
size_t buffer_strcpy(buffer *dest, const char *src);

// Convert a buffer to a null-terminated string. Uses the `used` var to determine length.
char *buffer_to_string(buffer *buff);

// Free a buffer. Called when a buffer is no longer needed.
void free_buffer(buffer *buff);

#endif // CBUFFER_H

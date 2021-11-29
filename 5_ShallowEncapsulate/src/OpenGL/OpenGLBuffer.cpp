#include "OpenGLBuffer.h"
#include <glad/glad.h>

gen::OpenGLVertextBuffer::OpenGLVertextBuffer(uint32_t size)
{
	glCreateBuffers(1, &m_renderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
	glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

gen::OpenGLVertextBuffer::OpenGLVertextBuffer(float* vertices, uint32_t size)
{
	glCreateBuffers(1, &m_renderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
	glBufferData(GL_ARRAY_BUFFER, size,  vertices, GL_DYNAMIC_DRAW);
}

gen::OpenGLVertextBuffer::~OpenGLVertextBuffer()
{
	glDeleteBuffers(1, &m_renderID);
}

void gen::OpenGLVertextBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
}

void gen::OpenGLVertextBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void gen::OpenGLVertextBuffer::SetData(const void* data, uint32_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

gen::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
{
	// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
	// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
	glCreateBuffers(1, &m_renderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}

gen::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_renderID);
}

void gen::OpenGLIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID);
}

void gen::OpenGLIndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

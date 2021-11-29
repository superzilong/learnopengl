#include "OpenGLShader.h"
#include <glad/glad.h>

namespace gen
{
	namespace utils
	{
		static GLenum ShaderTypeFromString(const std::string& type)
		{
			if (type == "vertex")
			{
				return GL_VERTEX_SHADER;
			}
			if (type == "fragment" || type == "pixel")
			{
				return GL_FRAGMENT_SHADER;
			}
			GEN_ASSERT(false, "Unknown shader type!");
			return 0;
		}
	}
}



gen::OpenGLShader::OpenGLShader(const std::string& filepath)
{
}

gen::OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
{
}

gen::OpenGLShader::~OpenGLShader()
{
}

void gen::OpenGLShader::Bind() const
{
}

void gen::OpenGLShader::Unbind() const
{
}

void gen::OpenGLShader::SetInt(const std::string& name, int value)
{
}

void gen::OpenGLShader::SetIntArray(const std::string& name, int* values, uint32_t count)
{
}

void gen::OpenGLShader::SetFloat()
{
}

void gen::OpenGLShader::SetFloat2()
{
}

void gen::OpenGLShader::SetFloat3()
{
}

void gen::OpenGLShader::SetFloat4()
{
}

void gen::OpenGLShader::SetMat4()
{
}

const std::string& gen::OpenGLShader::GetName()
{
}

gen::SP<gen::OpenGLShader> gen::OpenGLShader::Create(const std::string& filepath)
{
}

gen::SP<gen::OpenGLShader> gen::OpenGLShader::Create(const std::string& name, const std::string& veterSrc,
	const std::string& fragmentSrc)
{
}

void gen::ShaderLibrary::Add(const std::string& name, const SP<OpenGLShader>& shader)
{
}

void gen::ShaderLibrary::Add(SP<OpenGLShader>& filepath)
{
}

gen::SP<gen::OpenGLShader> gen::ShaderLibrary::Load(const std::string& filepath)
{
}

gen::SP<gen::OpenGLShader> gen::ShaderLibrary::Load(const std::string& name, const std::string& filepath)
{
}

gen::SP<gen::OpenGLShader> gen::ShaderLibrary::Get(const std::string& name)
{
}

bool gen::ShaderLibrary::Exists(const std::string& name) const
{
}

#include "OpenGLShader.h"

#include <array>
#include <glad/glad.h>
#include <fstream>

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

void gen::OpenGLShader::UploadUniformInt(const std::string& name, int value)
{
}

void gen::OpenGLShader::UploadUniformIntArray(const std::string& name, int* values, uint32_t count)
{
}

void gen::OpenGLShader::UploadUniformFloat(const std::string& name, float value)
{
}

void gen::OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& value)
{
}

void gen::OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& value)
{
}

void gen::OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& value)
{
}

void gen::OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
{
}

void gen::OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
{
}

gen::SP<gen::OpenGLShader> gen::OpenGLShader::Create(const std::string& filepath)
{
}

gen::SP<gen::OpenGLShader> gen::OpenGLShader::Create(const std::string& name, const std::string& veterSrc,
	const std::string& fragmentSrc)
{
}

std::string gen::OpenGLShader::ReadFile(const std::string& filepath)
{
	std::string result;
	std::ifstream in(filepath, std::ios::in | std::ios::binary);
	if (in)
	{
		in.seekg(0, std::ios::end);
		size_t size = in.tellg();
		if (size != -1)
		{
			result.resize(size);
			in.seekg(0, std::ios::beg);
			in.read(&result[0], size);
		}
	}
	GEN_LOG_ERROR("Could not open file {0}", filepath);
	return result;
}

std::unordered_map<GLenum, std::string> gen::OpenGLShader::PreProcess(const std::string& source)
{
	std::unordered_map<GLenum, std::string> shaderSources;
	const char* typeToken = "#type";
	size_t typeTokenLength = strlen(typeToken);
	size_t pos = source.find(typeToken, 0); //Start of shader type declaration line
	while(pos != std::string::npos)
	{
		size_t eol = source.find_first_of("\r\n", pos); //End of shader type declaration line
		GEN_ASSERT(eol != std::string::npos, "Syntax error");
		size_t begin = pos + typeTokenLength + 1;  //Start of shader type name (after "#type " keyword)
		std::string type = source.substr(begin, eol - begin);
		GEN_ASSERT(utils::ShaderTypeFromString(type), "Invalid shader type specified");

		size_t nextLinePos = source.find_first_not_of("\r\n", eol);
		GEN_ASSERT(nextLinePos != std::string::npos, "Syntax error");
		pos = source.find(typeToken, nextLinePos);

		shaderSources[utils::ShaderTypeFromString(type)] =
			(pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
	}
	return shaderSources;
}

void gen::OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
{
	GLuint program = glCreateProgram();
	GEN_ASSERT(shaderSources.size() <= 2, "We only support 2 shaders for now.");
	std::array<GLenum, 2> glShaderIDs;
	int glShaderIDIndex = 0;
	for(auto& kv : shaderSources)
	{
		GLenum type = kv.first;
		const std::string& source = kv.second;

		GLuint shader = glCreateShader(type);

		const GLchar* sourceCStr = source.c_str();
		glShaderSource(shader, 1, &sourceCStr, 0);

		glCompileShader(shader);

		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	}
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

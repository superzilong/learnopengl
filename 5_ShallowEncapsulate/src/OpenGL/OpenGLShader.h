#pragma once
#include <memory>
#include <string>

#include "Core/Base.h"

namespace gen
{
	class OpenGLShader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		void Bind() const;
		void Unbind() const;

		void SetInt(const std::string& name, int value);
		void SetIntArray(const std::string& name, int* values, uint32_t count);
		void SetFloat();
		void SetFloat2();
		void SetFloat3();
		void SetFloat4();
		void SetMat4();

		const std::string& GetName();

		static SP<OpenGLShader> Create(const std::string& filepath);
		static SP<OpenGLShader> Create(const std::string& name, const std::string& veterSrc, const std::string& fragmentSrc );
	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string& name, const SP<OpenGLShader>& shader);
		void Add(SP<OpenGLShader>& filepath);
		SP<OpenGLShader> Load(const std::string& filepath);
		SP<OpenGLShader> Load(const std::string& name, const std::string& filepath);

		SP<OpenGLShader> Get(const std::string& name);
		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, SP<OpenGLShader>> m_shaders;
	};
}

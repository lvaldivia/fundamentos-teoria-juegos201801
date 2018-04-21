#include "GLS_Program.h"
#include <fstream>
#include <vector>
#include <iostream>
#include "Error.h"

using namespace std;


GLS_Program::GLS_Program() : 
	_programID(0), _vertexShaderID(0),_fragmentShaderID(0),
	_numAtribute(0)
{
}


void GLS_Program::linkShader() {
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	glLinkProgram(_programID);

	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(_programID);
		//Don't leak shaders either.

		fatalError("Shaders no linkeados "+
					printf("%s",&(infoLog[0]))
					);

		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
		return;
	}
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}


void GLS_Program::compileShaders(const string& vertexShaderFilePath,
	const string& fragmentShaderFilePath) {

	_programID = glCreateProgram();
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0) {

	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0) {

	}
	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);

}

void GLS_Program::addAtribute(const string name) {
	
	glBindAttribLocation(_programID,
					_numAtribute++,name.c_str());

	cout << name << _numAtribute;
}

void GLS_Program::use() {
	glUseProgram(_programID);
	for (int i = 0; i < _numAtribute; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLS_Program::unuse() {
	glUseProgram(0);
	for (int i = 0; i < _numAtribute; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

GLuint GLS_Program::getUniformLocation(const string& name) {
	GLuint location = glGetUniformLocation(_programID, 
					name.c_str());

	if (location == GL_INVALID_INDEX) {
		fatalError("No hay uniform variable " 
						+ name + " en el shader");
	}
	return location;
}

void GLS_Program::compileShader(const string& shaderPath, GLuint id) {

	string filecontent = "";
	string line = "";

	ifstream shaderFile(shaderPath);
	if (shaderFile.fail()) {
		fatalError("No encuentra el archivo " + shaderPath);
	}
	while (getline(shaderFile, line)) {
		filecontent += line + "\n";
	}
	shaderFile.close();
	const char* contents = filecontent.c_str();
	glShaderSource(id, 1, &contents, nullptr);

	glCompileShader(id);

	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &infoLog[0]);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.

		//std::cout << shaderPath << endl;

		fatalError("Shaders no compilaron " +
			printf("%s", &(infoLog[0]))
		);

		glDeleteShader(id); // Don't leak the shader.
		return;
	}
}


GLS_Program::~GLS_Program()
{
}
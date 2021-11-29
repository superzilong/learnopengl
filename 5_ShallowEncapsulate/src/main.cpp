#include "Core/Assert.h"
#include "Core/Log.h"
#include "Window/Window.h"


int main(int argc, char* argv[])
{
	Log::Init();
	gen::WindowProps props;
	gen::Window win(props);
	return 0;
}

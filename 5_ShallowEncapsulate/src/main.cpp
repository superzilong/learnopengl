#include "Core/Assert.h"
#include "Core/Log.h"
#include "Window/Window.h"


int main(int argc, char* argv[])
{
	Log::Init();
	GEN_ASSERT(0);
	gen::WindowProps props;
	gen::Window win(props);
	return 0;
}

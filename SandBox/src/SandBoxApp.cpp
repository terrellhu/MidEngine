#include <MidEngine.h>

class SandBox : public ME::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

ME::Application* ME::CreateApplication()
{
	return new SandBox();
}
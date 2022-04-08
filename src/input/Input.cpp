#include "Input.h"

	namespace Input
	{
		GLFWwindow* win;
		bool mouseButtonPressedData[7] = {};
		float mouseX = 0.0f;
		float mouseY = 0.0f;
		float mouseScrollX = 0.0f;
		float mouseScrollY = 0.0f;


     

		void mouseCallback(GLFWwindow* window, double xpos, double ypos)
		{
			mouseY += ypos - 10;
            mouseX += xpos - 10;
            
            glfwSetCursorPos(window,10,10);
		}

		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			if (button >= 0 && button < GLFW_MOUSE_BUTTON_LAST)
			{
				mouseButtonPressedData[button] = (action == GLFW_PRESS);
			}
		}
   		
		void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
		{
			mouseScrollX = (float)xoffset;
			mouseScrollY = (float)yoffset;
		}
		void loadCallbacks(GLFWwindow* Window){
           
			glfwSetCursorPosCallback(Window, &mouseCallback);
			glfwSetMouseButtonCallback(Window, &mouseButtonCallback);
			glfwSetScrollCallback(Window, &mouseScrollCallback);
			win = Window;
        }
		bool isKeyDown(int key )
		{
			if (key >= 0 && key < GLFW_KEY_LAST)
			{
				return glfwGetKey(win,key) == GLFW_PRESS;
			}

			return false;
		}

		bool isMouseButtonDown(int mouseButton)
		{
			if (mouseButton >= 0 && mouseButton < GLFW_MOUSE_BUTTON_LAST)
			{
				return mouseButtonPressedData[mouseButton];
			}

			return false;
		}
	}

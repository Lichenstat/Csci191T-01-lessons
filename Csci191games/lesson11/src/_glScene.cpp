#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //ctor
}

_glScene::~_glScene()
{
    //dtor
}

GLint _glScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    _glLight myLight(GL_LIGHT0);

    modelTex->loadTexture("images/car.jpg");
    background->parallaxInit("images/plx.jpg");
    backgroundtwo->parallaxInit("images/plx2.png");

    timer -> startTimer();
    myPly -> playerInit(5, 3);  // how many frames (X, Y) frames is the sprite sheet
    myPly -> plyImage -> loadTexture("images/plyspritesheet.png");

    texEnms -> loadTexture("images/enemy.png");

    snds->initSounds();
    snds->playMusic("sounds/opening.mp3");

    for(int i = 0; i < 20; i++)
    {
        enms[i].tex = texEnms -> tex;
        enms[i].posE.x = (float)rand()/float(RAND_MAX)*5-2.5;
        enms[i].posE.y = -0.5;

        enms[i].placeEnms(enms[i].posE);
        enms[i].sizeE.y = enms[i].sizeE.x = (float)(rand()%12)/30.0;
    }

    return true;
}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.6f, 0.1f, 0.2f, 0.3f);                   // change this if you want to change color of scene
    glLoadIdentity();


    glPushMatrix();
    glScalef(3.33, 3.33, 1.0);
    glBindTexture(GL_TEXTURE_2D, background->plxTexture->tex);
    background->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    glPushMatrix();
    glScalef(3.33, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, backgroundtwo->plxTexture->tex);
    background->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    background->scroll(false, "left", 0.001);                // auto background scrolling

    //glTranslated(0, 0, -8);                                 // place in the scene
    //glColor3f(1.0, 0.3, 0.2);                               // set a color to the object

    //glBindTexture(GL_TEXTURE_2D,modelTex->tex);             // to use texture on the teapot
    //modelTeapot -> drawModel();
    //glutSolidTorus(0.2, 0.5, 20, 20);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
    myPly -> drawPlayer();

    if(timer -> getTicks() > 120)
    {
        myPly -> actions();
        timer->resetTime();
    /*
    myPly -> xMin += 1/myPly -> framesX;
    myPly -> xMax += 1/myPly -> framesX;
    myPly -> yMin += 1/myPly -> framesY;
    myPly -> yMax += 1/myPly -> framesY;
    */
    timer -> resetTime();
    }
    glPopMatrix();

    for(int i = 0; i < 20; i++)
    {
        if(enms[i].posE.x < -2.0)
        {
            enms[i].actions = 0;
            enms[i].speed = 0.01;
        }
        else if(enms[i].posE.x > 2.0)
        {
            enms[i].actions = 1;
            enms[i].speed = -0.01;
        }

    enms[i].posE.x += enms[i].speed;
    enms[i].actionsEnms();
    enms[i].drawEnms();
    }
}

void _glScene::resizeGLScene(int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    float aspectRatio = (float)width/(float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45.0, aspectRatio, 0.1, 100);

    glOrtho(-5.0, 5.0, -3.5, 3.5, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int _glScene::winMSG(HWND   hWnd,			        // Handle For This Window
                     UINT	uMsg,			        // Message For This Window
                     WPARAM	wParam,			        // Additional Message Information
                     LPARAM	lParam)
{
    kbMS->wParam = wParam;
    switch (uMsg)									// Check For Windows Messages
	{

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    //kbMS->wParam = wParam;
		    kbMS->keyPressed(modelTeapot);
			kbMS->moveEnv(background, .005);
			kbMS->keyPressed(myPly);
			kbMS->keyPressed(snds);
			break;							        // Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
            //kbMS->wParam = wParam;
		    kbMS->keyUp();
		    kbMS->keyUp(myPly);
			break;							    // Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            kbMS->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_RBUTTONDOWN:
        {
            kbMS->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_MBUTTONDOWN:
        {
            break;
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            kbMS->mouseUp();
            break;
        }

        case WM_MOUSEMOVE:
        {
            kbMS->mouseMove(modelTeapot, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_MOUSEWHEEL:
        {
            kbMS->mouseWheel(modelTeapot, (float)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
        }

	}
}


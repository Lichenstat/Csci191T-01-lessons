#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //cgs state = landing;
    doneLoading = false;
    inRelationToPlayer = .060;
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

    if (state == landing)
    {
        snds->stopAllSounds();
        landingBG->parallaxInit("images/menu/landing.png");
        doneLoading = true;

    }

    if(state == menu)
    {
        snds->stopAllSounds();
        mainSceneBG->parallaxInit("images/menu/menuSceneBg.jpg");

        startGameBtn->startGBtnTex->loadTexture("images/menu/startBtn.png");
        helpBtn->helpBtnTex->loadTexture("images/menu/helpBtn.png");
        exitBtn->exitBtnTex->loadTexture("images/menu/exitBtn.png");
        creditBtn->creditBtnTex->loadTexture("images/menu/creditBtn.png");
        doneLoading = true;
    }

    if(state == help){

        snds->stopAllSounds();

        mainSceneBG->parallaxInit("images/menu/helpSceneBg.jpg");
        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        doneLoading = true;
    }

    if(state == credit){

        snds->stopAllSounds();

        creditSceneBG->parallaxInit("images/menu/creditSceneBg.png");
        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        doneLoading = true;
    }

    if(state == levelOne)
    {
        //modelTex->loadTexture("images/car.jpg");

        //levelOne backgrounds sources
        skyBg->parallaxInit("images/levelOne/sky.png");
        groundBg->parallaxInit("images/levelOne/ground.png");
        fogBg->parallaxInit("images/levelOne/fog.png");
        cloudOneBg->parallaxInit("images/levelOne/cloud fg.png");
        cloudTwoBg->parallaxInit("images/levelOne/clouds bg.png");
        smallMountainsBg->parallaxInit("images/levelOne/mountains fg.png");
        bigMountainsBg->parallaxInit("images/levelOne/mountains bg.png");
        sunBg->parallaxInit("images/levelOne/sun.png");
        mountainBG->parallaxInit("images/levelOne/mountains mg.png");

        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        firstPlatform->initialize();
        _objectinteract_max::changePosition(firstPlatform->platform, 1.0, -2.0);
        _objectinteract_max::changeScale(firstPlatform->platform, 0.5, 0.7);

        timer -> startTimer();
        //myPly -> playerInit(5, 3);  // how many frames (X, Y) frames is the sprite sheet
        //myPly -> plyImage -> loadTexture("images/plyspritessheet.jpg");

        //texEnms -> loadTexture("images/enemy.png");

        //snds->initSounds();
        //snds->playMusic("sounds/opening.mp3");

        //fnts->initFonts("images/fonts.png");
        //fnts->buildFont("aAa");
        /*
        for(int i = 0; i < 20; i++)
        {
            enms[i].tex = texEnms -> tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX)*5-2.5;
            enms[i].posE.y = -0.5;

            enms[i].placeEnms(enms[i].posE);
            enms[i].sizeE.y = enms[i].sizeE.x = (float)(rand()%12)/30.0;
        }*/

        //Max's addition to scene
        itemTimer->startTimer();

        // initializing objects (in this case it is a player 1 and healthpacks)
        player1->initialize();
        _objectinteract_max::changePosition(player1->player, 0.0, -2.1);

        hud->initialize();

        healthpack1->initialize();
        _objectinteract_max::changePosition(healthpack1->healthpack, -2.0, -2.0);
        _objectinteract_max::changeScale(healthpack1->healthpack, 0.5, 0.5);
        healthpack2->initialize();
        _objectinteract_max::changePosition(healthpack2->healthpack, 2.0, -2.0);
        _objectinteract_max::changeScale(healthpack2->healthpack, 0.5, 0.5);

        mine1->initialize();
        _objectinteract_max::changePosition(mine1->mine, -2.0, 1.0);
        turret1->initialize();
        _objectinteract_max::changePosition(turret1->turretParts, -2.5, -2.2);

        //Eric's projectiles
        pistol->projInit(1, 1);
        pistol->weaponSkin->loadTexture("images/pistol.png");
        pistol->weaponHold = pistol->P;
        pistol->proj->loadTexture("images/bullet.png");
        pistol->action = pistol->PISTOL;
        pistol->framesX = 1.0;
        pistol->xMax = 1.0/pistol->framesX;
        pistol->vel = 0.1;
        pistol->weaponDmg = 10;
        pistol->projScale.x = 0.2;
        pistol->projScale.y = 0.2;

        grenadelauncher->projInit(8, 1);
        grenadelauncher->weaponSkin->loadTexture("images/grenadeLauncher.png");
        grenadelauncher->weaponHold = grenadelauncher->G;
        grenadelauncher->proj->loadTexture("images/ballRoll.png");
        grenadelauncher->action = grenadelauncher->GRENADELAUNCHER;
        grenadelauncher->framesX = 8.0;
        grenadelauncher->xMax = 1.0/grenadelauncher->framesX;
        grenadelauncher->vel = 0.009;
        grenadelauncher->accel = 0.0005;
        grenadelauncher->weaponDmg = 25;
        grenadelauncher->projScale.x = 0.2;
        grenadelauncher->projScale.y = 0.2;

        laserGun->projInit(1, 1);
        laserGun->weaponSkin->loadTexture("images/beamGun.png");
        laserGun->weaponHold = laserGun->B;
        laserGun->proj->loadTexture("images/laserSprite.png");
        laserGun->action = laserGun->BEAM;
        laserGun->framesX = 1.0;
        laserGun->xMax = 1.0/laserGun->framesX;
        laserGun->vel = 0.3;
        laserGun->weaponDmg = 50;
        laserGun->projScale.x = 0.2;
        laserGun->projScale.y = 0.2;

        wpns = pistol;        //MANUAL START TO WEAPON, should start with a pistol but set to laserGun for ease of destroying turret and mine
        //----------

        doneLoading = true;
    }

    return true;
}

GLint _glScene::drawScene()
{
    if(state == landing)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glLoadIdentity();

        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, landingBG->plxTexture->tex);
        mainSceneBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();

    }

    if(state == menu)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glLoadIdentity();

        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, mainSceneBG->plxTexture->tex);
        mainSceneBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, startGameBtn->startGBtnTex->tex);
        startGameBtn->drawButton(0.0,1.0,-1.0,1.0,0.5,1.0);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, helpBtn->helpBtnTex->tex);
        helpBtn->drawButton(0.0,0.0,-1.0,1.0,0.5,1.0);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, creditBtn->creditBtnTex->tex);
        //glBindTexture(GL_TEXTURE_2D, exitBtn->exitBtnTex->tex);
        //exitBtn->drawButton(0.0,-1.0,-1.0,1.0,0.5,1.0);
        creditBtn->drawButton(0.0,-1.0,-1.0,1.0,0.5,1.0);
        glPopMatrix();

        glPushMatrix();
        //glBindTexture(GL_TEXTURE_2D, creditBtn->creditBtnTex->tex);
        glBindTexture(GL_TEXTURE_2D, exitBtn->exitBtnTex->tex);
        exitBtn->drawButton(0.0,-2.0,-1.0,1.0,0.5,1.0);

        glPopMatrix();

    }
    if(state == help){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glLoadIdentity();

        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, mainSceneBG->plxTexture->tex);
        mainSceneBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, backBtn->backBtnTex->tex);
        backBtn->drawButton(0.0,-1.5,-1.0,1.0,0.5,1.0);
        glPopMatrix();

    }

    if(state == credit){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glLoadIdentity();

        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, creditSceneBG->plxTexture->tex);
        creditSceneBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, backBtn->backBtnTex->tex);
        backBtn->drawButton(0.0,-1.5,-1.0,1.0,0.5,1.0);
        glPopMatrix();

    }

    if(state == levelOne)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // change this if you want to change color of scene
        glLoadIdentity();

        //LevelOne background
        //sky
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, skyBg->plxTexture->tex);
        skyBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //sky clouds top
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, cloudTwoBg->plxTexture->tex);
        cloudTwoBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //fog
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, fogBg->plxTexture->tex);
        fogBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //sun
        /*
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, sunBg->plxTexture->tex);
        sunBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        */
        //big mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, bigMountainsBg->plxTexture->tex);
        bigMountainsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, mountainBG->plxTexture->tex);
        mountainBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //bottom clouds
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, cloudOneBg->plxTexture->tex);
        cloudOneBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //small mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, smallMountainsBg->plxTexture->tex);
        smallMountainsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //ground
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, groundBg->plxTexture->tex);
        groundBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        firstPlatform->draw();
        firstPlatform->interact(player1->player);

        //clouds effect auto scrolling
        cloudOneBg->scroll(true, "left", 0.0001);                // auto background scrolling
        cloudTwoBg->scroll(true, "left", 0.0003);

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, backBtn->backBtnTex->tex);
        backBtn->drawButton(4.7,3.4,-1.0,0.5,0.3,1.0);
        glPopMatrix();

        //glTranslated(0, 0, -8);                                 // place in the scene
        //glColor3f(1.0, 0.3, 0.2);                               // set a color to the object

        //glBindTexture(GL_TEXTURE_2D,modelTex->tex);             // to use texture on the teapot
        //modelTeapot -> drawModel();
        //glutSolidTorus(0.2, 0.5, 20, 20);

        //glPushMatrix();
        //glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        //myPly -> drawPlayer();

        //if(timer -> getTicks() > 120)
        //{
            //myPly -> actions();
            //timer->resetTime();
            /*
            myPly -> xMin += 1/myPly -> framesX;
            myPly -> xMax += 1/myPly -> framesX;
            myPly -> yMin += 1/myPly -> framesY;
            myPly -> yMax += 1/myPly -> framesY;
            */
            //timer -> resetTime();
        //}
        //glPopMatrix();
        /*
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
        }*/

        //glScalef(5.0, 5.0, 0);
        //glTranslatef(0, 0.0, -1);
        //fnts->drawFonts();

        // Max's includes to scene
        // drawing and updating necessary objects
        hud->draw();
        hud->interact(player1->playerHealth);

        healthpack1->draw();
        healthpack1->interact(player1->player);
        healthpack2->draw();
        healthpack2->interact(player1->player);

        mine1->draw();
        mine1->interact(player1->player);

        turret1->draw();
        turret1->interact(player1->player);

        player1->draw();

        if(itemTimer->getTicks() > 120)
        {
            player1->animate();
            healthpack1->animate();
            healthpack2->animate();

            mine1->animate();
            turret1->animate();

            itemTimer->resetTime();
        }

        player1->interact(healthpack1->healthpack);
        player1->interact(healthpack2->healthpack);
        player1->interact(mine1->mine);
        player1->interact(turret1->turrethead);


        //Eric's drawings
        if(wpns->action == wpns->PISTOL){
            wpns = pistol;
            pistol->vel = 0.2;
            pistol->weaponDmg = 10;
            pistol->projScale.x = 0.2;
            pistol->projScale.y = 0.2;
        }
        if(wpns->action == wpns->GRENADELAUNCHER){
            wpns = grenadelauncher;
            grenadelauncher->vel = 0.09;
            grenadelauncher->accel = 0.005;
            grenadelauncher->weaponDmg = 25;
            grenadelauncher->projScale.x = 0.2;
            grenadelauncher->projScale.y = 0.2;
        }
        if(wpns->action == wpns->BEAM){
            wpns = laserGun;
            laserGun->vel = 0.3;
            laserGun->weaponDmg = 50;
            laserGun->projScale.x = 0.2;
            laserGun->projScale.y = 0.2;
        }
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, wpns->proj->tex);
            wpns->drawProj();
            glBindTexture(GL_TEXTURE_2D, wpns2->proj->tex);
            wpns2->drawProj();
            glBindTexture(GL_TEXTURE_2D, pistol->weaponSkin->tex);
            pistol->drawWeapon();
            glBindTexture(GL_TEXTURE_2D, grenadelauncher->weaponSkin->tex);
            grenadelauncher->drawWeapon();
            glBindTexture(GL_TEXTURE_2D, laserGun->weaponSkin->tex);
            laserGun->drawWeapon();
            if(timer->getTicks() > 15)
            {
                wpns->weaponAction(player1->player);
                if(col->projHit(wpns, mine1->mine))
                {
                    wpns->hitToOrigin(player1->player);
                    mine1->health -= wpns->weaponDmg;
                    if(mine1->health <= 0){
                        mine1->mine->obj.pos.z = -9.0;
                        mine1->mine->obj.exist = false;
                    }
                    grenadelauncher->weaponSpawn(mine1->mine, grenadelauncher);
                }
                if(col->projHit(wpns, turret1->turrethead))
                {
                    wpns->hitToOrigin(player1->player);
                    turret1->health-= wpns->weaponDmg;
                    if(turret1->health <= 0){
                        turret1->turrethead->obj.pos.z = -9.0;
                        turret1->turretbarrel->obj.pos.z = -9.0;
                        turret1->turrethead->obj.exist = false;
                    }
                    laserGun->weaponSpawn(turret1->turrethead, laserGun);
                }
                grenadelauncher->weaponFall();
                laserGun->weaponFall();
                timer->resetTime();
            }
        glPopMatrix();

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

    glOrtho(-5.0, 5.0, -3.5, 3.5, 0.1, 100);  // will readjust game view to match game window size
    //glOrtho(-width/350.0, width/350.0, -height/350.0, height/350.0, 0.1, 100); // will cut off game view when changing in game window

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
        if (player1->playerHealth > 0)
        {
            //kbMS->wParam = wParam;
            //kbMS->keyPressed(modelTeapot);
            kbMS->moveEnv(groundBg, .005);
            kbMS->moveEnv(mountainBG, .0045);
            kbMS->moveEnv(smallMountainsBg, .0048);
            kbMS->moveEnv(bigMountainsBg, .002);
            //kbMS->keyPressed(myPly);
            if(state != menu)
            {
                kbMS->keyPressed(snds);
            }
            kbMS->moveObj(firstPlatform->platform, 0.06);
            //Max's additions to scene
            kbMS->movePly(player1, 0.030);                  // will flip player in said direction and translate the desired direciton
            kbMS->moveObj(healthpack1->healthpack, inRelationToPlayer);  // healthpacks move at speed given
            kbMS->moveObj(healthpack2->healthpack, inRelationToPlayer);
            kbMS->moveObj(mine1->mine, inRelationToPlayer);
            kbMS->moveObj(turret1->turretParts, inRelationToPlayer);
            //-----------

            //Eric's keyboard imputs
            kbMS->keyPressed(wpns);
            kbMS->keyPressed(pistol);
            kbMS->keyPressed(grenadelauncher);
            kbMS->keyPressed(laserGun);
            kbMS->keyPressed(shockRifle);
            kbMS->weaponPickUp(pistol, wpns, player1->player);
            kbMS->weaponPickUp(grenadelauncher, wpns, player1->player);
            kbMS->weaponPickUp(laserGun, wpns, player1->player);
            kbMS->weaponPickUp(shockRifle, wpns, player1->player);

            //--------------
        }
        //--------
        break;							        // Jump Back
    }

    case WM_KEYUP:								// Has A Key Been Released?
    {
        //kbMS->wParam = wParam;
        kbMS->keyUp();
        kbMS->keyUp(myPly);

        //Max's additions to scene
        kbMS->movePly(player1,  0.0);       // player will stand after moving
        //--------

        break;							    // Jump Back
    }

    case WM_LBUTTONDOWN:
    {
        GetOGLPos(LOWORD(lParam), HIWORD(lParam));

        if(state == menu)
        {

            if(posmX > -0.49 && posmX < 0.49 && posmY >.80 && posmY < 1.2)
            {
                state = levelOne;

                doneLoading = false;
            }
             if(posmX > -0.49 && posmX < 0.49 && posmY >-0.24 && posmY < 0.24)
            {
                state = help;

                doneLoading = false;
            }

            if(posmX > -0.49 && posmX < 0.49 && posmY >-1.27 && posmY < -0.75)
            {
                state = credit;
                doneLoading = false;
                //std::exit(0);
                //state = exit;

                //doneLoading = false;
            }

            if(posmX > -0.49 && posmX < 0.49 && posmY >-2.25 && posmY < -1.78)
            {
                std::exit(0);
                //state = help;

                //doneLoading = false;
            }
        }
        if(state == help){
            if(posmX > -0.49 && posmX < 0.49 && posmY >-1.76 && posmY < -1.25)
            {
                state = menu;

                doneLoading = false;
            }
        }
        if(state == credit){
            if(posmX > -0.49 && posmX < 0.49 && posmY >-1.76 && posmY < -1.25)
            {
                state = menu;

                doneLoading = false;
            }
        }
        if(state == levelOne)
        {
            if(posmX > 4.42 && posmX < 5.0 && posmY > 3.24 && posmY < 3.5)
            {
                state = menu;

                doneLoading = false;
            }

            //Eric's aditions
            kbMS->anglesForShots(wpns, LOWORD(lParam), HIWORD(lParam));
            //----
        }

        cout << "Mouse Click On Location: " << posmX << " " << posmY << endl;

        //kbMS->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
        break;
    }

    case WM_RBUTTONDOWN:
    {
        //kbMS->mouseDown(modelTeapot, LOWORD(lParam), HIWORD(lParam));
        //Eric's additons
        GetOGLPos(LOWORD(lParam), HIWORD(lParam));
        if(levelOne){
        }
        //-----
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
        kbMS->anglesForShots(wpns, LOWORD(lParam), HIWORD(lParam));
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


#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //cgs state = landing;
    doneLoading = false;
    inRelationToPlayer = .060;

    for(int i = 0; i < 5; i++)
    {
        mine1.push_back(new _mine());
    }
    for(int i = 0; i < 5; i++)
    {
        turret1.push_back(new _turret());
    }
    for(int i = 0; i < 10; i++)
    {
        mine2.push_back(new _mine());
    }
    for(int i = 0; i < 10; i++)
    {
        turret2.push_back(new _turret());
    }

    for(int i = 0; i < 15; i++)
    {
        mine3.push_back(new _mine());
    }

    for(int i = 0; i < 15; i++)
    {
        turret3.push_back(new _turret());
    }

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

    if(state == help)
    {

        snds->stopAllSounds();

        mainSceneBG->parallaxInit("images/menu/helpSceneBg.jpg");
        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        doneLoading = true;
    }

    if(state == credit)
    {

        snds->stopAllSounds();

        creditSceneBG->parallaxInit("images/menu/creditSceneBg.png");
        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        doneLoading = true;
    }

    if(state == levelOne)
    {

        //levelTwo backgrounds sources
        lv1cloudOneBg->parallaxInit("images/levelTwo/clouds bg.png");
        lv1cloudTwoBg->parallaxInit("images/levelTwo/clouds fg.png");
        lv1fogBg->parallaxInit("images/levelTwo/fog.png");
        lv1mountainsBg->parallaxInit("images/levelTwo/forest and mountains.png");
        lv1forestBg->parallaxInit("images/levelTwo/forest fg.png");
        lv1groundBg->parallaxInit("images/levelTwo/ground.png");
        lv1bigMountainBg->parallaxInit("images/levelTwo/mountain.png");
        lv1skyBg->parallaxInit("images/levelTwo/sky.png");

        timer -> startTimer();

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


        for(int i = 0; i < 5; i++)
        {

            mine1[i]->initialize();
            _objectinteract_max::changePosition(mine1[i]->mine,((rand()%10)+1), 1);

        }

        int x = ((rand()%10)+1);
        for(int i = 0; i < 5; i++)
        {

            turret1[i]->initialize();
            _objectinteract_max::changePosition(turret1[i]->turretParts, x, -2.2);
            _objectinteract_max::changePosition(turret1[i]->turretbullet, x, -2.2);
            x = ((rand()%10)+1);
        }

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
        laserGun->projScale.x = 0.4;
        laserGun->projScale.y = 0.2;

        shockRifle->projInit(1, 1);
        shockRifle->weaponSkin->loadTexture("images/shockRifle.png");
        shockRifle->weaponHold = shockRifle->S;
        shockRifle->proj->loadTexture("images/shockBullet.png");
        shockRifle->action = shockRifle->SHOCKRIFLE;
        shockRifle->framesX = 1.0;
        shockRifle->xMax = 1.0/shockRifle->framesX;
        shockRifle->vel = 0.4;
        shockRifle->weaponDmg = 100;
        shockRifle->projScale.x = 0.3;
        shockRifle->projScale.y = 0.15;

        shockBulOne->projInit(1, 1);
        shockBulOne->proj->loadTexture("images/shockBullet.png");
        shockBulOne->action = shockBulOne->SHOCKRIFLE;
        shockBulOne->framesX = 1.0;
        shockBulOne->xMax = 1.0/shockBulOne->framesX;
        shockBulOne->vel = 0.4;
        shockBulOne->weaponDmg = 100;
        shockBulOne->projScale.x = 0.3;
        shockBulOne->projScale.y = 0.15;

        shockBulTwo->projInit(1, 1);
        shockBulTwo->proj->loadTexture("images/shockBullet.png");
        shockBulTwo->action = shockBulTwo->SHOCKRIFLE;
        shockBulTwo->framesX = 1.0;
        shockBulTwo->xMax = 1.0/shockBulTwo->framesX;
        shockBulTwo->vel = 0.4;
        shockBulTwo->weaponDmg = 100;
        shockBulTwo->projScale.x = 0.3;
        shockBulTwo->projScale.y = 0.15;

        wpns = pistol;        //MANUAL START TO WEAPON, should start with a pistol but set to laserGun for ease of destroying turret and mine
        //----------

        doneLoading = true;
    }

    if(state == levelTwo)
    {

        //levelThree backgrounds sources
        lv2cloudOneBg->parallaxInit("images/levelThree/clouds bg.png");
        lv2cloudTwoBg->parallaxInit("images/levelThree/clouds fg.png");
        lv2airBg->parallaxInit("images/levelThree/air.png");
        lv2bigMountainBg->parallaxInit("images/levelThree/mountains bg.png");
        lv2mediumMountainBg->parallaxInit("images/levelThree/mountains mg.png");
        lv2groundBg->parallaxInit("images/levelThree/ground.png");
        lv2smallMountainBg->parallaxInit("images/levelThree/mountains fg.png");
        lv2skyBg->parallaxInit("images/levelThree/sky.png");
        lv2starsBg->parallaxInit("images/levelThree/stars.png");

        timer -> startTimer();

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

        for(int i = 0; i < 10; i++)
        {

            mine2[i]->initialize();
            _objectinteract_max::changePosition(mine2[i]->mine,((rand()%15)+1), 1);

        }

        int x = ((rand()%15)+1);
        for(int i = 0; i < 10; i++)
        {

            turret2[i]->initialize();
            _objectinteract_max::changePosition(turret2[i]->turretParts, x, -2.2);
            _objectinteract_max::changePosition(turret2[i]->turretbullet, x, -2.2);
            x = ((rand()%15)+1);
        }


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

        grenadeBoom->projInit(5,5);
        grenadeBoom->proj->loadTexture("images/explosion.png");

        laserGun->projInit(1, 1);
        laserGun->weaponSkin->loadTexture("images/beamGun.png");
        laserGun->weaponHold = laserGun->B;
        laserGun->proj->loadTexture("images/laserSprite.png");
        laserGun->action = laserGun->BEAM;
        laserGun->framesX = 1.0;
        laserGun->xMax = 1.0/laserGun->framesX;
        laserGun->vel = 0.3;
        laserGun->weaponDmg = 50;
        laserGun->projScale.x = 0.4;
        laserGun->projScale.y = 0.2;

        shockRifle->projInit(1, 1);
        shockRifle->weaponSkin->loadTexture("images/shockRifle.png");
        shockRifle->weaponHold = shockRifle->S;
        shockRifle->proj->loadTexture("images/shockBullet.png");
        shockRifle->action = shockRifle->SHOCKRIFLE;
        shockRifle->framesX = 1.0;
        shockRifle->xMax = 1.0/shockRifle->framesX;
        shockRifle->vel = 0.4;
        shockRifle->weaponDmg = 100;
        shockRifle->projScale.x = 0.3;
        shockRifle->projScale.y = 0.15;

        shockBulOne->projInit(1, 1);
        shockBulOne->proj->loadTexture("images/shockBullet.png");
        shockBulOne->action = shockBulOne->SHOCKRIFLE;
        shockBulOne->framesX = 1.0;
        shockBulOne->xMax = 1.0/shockBulOne->framesX;
        shockBulOne->vel = 0.4;
        shockBulOne->weaponDmg = 100;
        shockBulOne->projScale.x = 0.3;
        shockBulOne->projScale.y = 0.15;

        shockBulTwo->projInit(1, 1);
        shockBulTwo->proj->loadTexture("images/shockBullet.png");
        shockBulTwo->action = shockBulTwo->SHOCKRIFLE;
        shockBulTwo->framesX = 1.0;
        shockBulTwo->xMax = 1.0/shockBulTwo->framesX;
        shockBulTwo->vel = 0.4;
        shockBulTwo->weaponDmg = 100;
        shockBulTwo->projScale.x = 0.3;
        shockBulTwo->projScale.y = 0.15;

        wpns = pistol;        //MANUAL START TO WEAPON, should start with a pistol but set to laserGun for ease of destroying turret and mine
        //----------


        doneLoading = true;
    }
    if(state == levelThree)
    {

        //levelOne backgrounds sources
        lvOskyBg->parallaxInit("images/levelOne/sky.png");
        lv0groundBg->parallaxInit("images/levelOne/ground.png");
        lvOfogBg->parallaxInit("images/levelOne/fog.png");
        lvOcloudOneBg->parallaxInit("images/levelOne/cloud fg.png");
        lvOcloudTwoBg->parallaxInit("images/levelOne/clouds bg.png");
        lvOsmallMountainsBg->parallaxInit("images/levelOne/mountains fg.png");
        lvObigMountainsBg->parallaxInit("images/levelOne/mountains bg.png");
        lvOsunBg->parallaxInit("images/levelOne/sun.png");
        lvOmountainBG->parallaxInit("images/levelOne/mountains mg.png");

        backBtn->backBtnTex->loadTexture("images/menu/backBtn.png");

        // firstPlatform->initialize();
        // _objectinteract_max::changePosition(firstPlatform->platform, 1.0, -2.0);
        // _objectinteract_max::changeScale(firstPlatform->platform, 0.5, 0.7);

        timer -> startTimer();

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

        for(int i = 0; i < 15; i++)
        {

            mine3[i]->initialize();
            _objectinteract_max::changePosition(mine3[i]->mine,((rand()%20)+1), 1);

        }

        int x = ((rand()%20)+1);
        for(int i = 0; i < 15; i++)
        {
            turret3[i]->initialize();
            _objectinteract_max::changePosition(turret3[i]->turretParts, x, -2.2);
            _objectinteract_max::changePosition(turret3[i]->turretbullet, x, -2.2);
            x = ((rand()%20)+1);
        }

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
        laserGun->projScale.x = 0.4;
        laserGun->projScale.y = 0.2;

        shockRifle->projInit(1, 1);
        shockRifle->weaponSkin->loadTexture("images/shockRifle.png");
        shockRifle->weaponHold = shockRifle->S;
        shockRifle->proj->loadTexture("images/shockBullet.png");
        shockRifle->action = shockRifle->SHOCKRIFLE;
        shockRifle->framesX = 1.0;
        shockRifle->xMax = 1.0/shockRifle->framesX;
        shockRifle->vel = 0.4;
        shockRifle->weaponDmg = 100;
        shockRifle->projScale.x = 0.3;
        shockRifle->projScale.y = 0.15;

        shockBulOne->projInit(1, 1);
        shockBulOne->proj->loadTexture("images/shockBullet.png");
        shockBulOne->action = shockBulOne->SHOCKRIFLE;
        shockBulOne->framesX = 1.0;
        shockBulOne->xMax = 1.0/shockBulOne->framesX;
        shockBulOne->vel = 0.4;
        shockBulOne->weaponDmg = 100;
        shockBulOne->projScale.x = 0.3;
        shockBulOne->projScale.y = 0.15;

        shockBulTwo->projInit(1, 1);
        shockBulTwo->proj->loadTexture("images/shockBullet.png");
        shockBulTwo->action = shockBulTwo->SHOCKRIFLE;
        shockBulTwo->framesX = 1.0;
        shockBulTwo->xMax = 1.0/shockBulTwo->framesX;
        shockBulTwo->vel = 0.4;
        shockBulTwo->weaponDmg = 100;
        shockBulTwo->projScale.x = 0.3;
        shockBulTwo->projScale.y = 0.15;

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
    if(state == help)
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
        glBindTexture(GL_TEXTURE_2D, backBtn->backBtnTex->tex);
        backBtn->drawButton(0.0,-1.5,-1.0,1.0,0.5,1.0);
        glPopMatrix();

    }

    if(state == credit)
    {
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

        //LevelTwo background
        //sky
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1skyBg->plxTexture->tex);
        lv1skyBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //bottom clouds
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1cloudOneBg->plxTexture->tex);
        lv1cloudOneBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //fog
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1fogBg->plxTexture->tex);
        lv1fogBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //big mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1bigMountainBg->plxTexture->tex);
        lv1bigMountainBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1mountainsBg->plxTexture->tex);
        lv1mountainsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //sky clouds top
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1cloudTwoBg->plxTexture->tex);
        lv1cloudTwoBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //forest
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1forestBg->plxTexture->tex);
        lv1forestBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //ground
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv1groundBg->plxTexture->tex);
        lv1groundBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        //clouds effect auto scrolling
        lv1cloudOneBg->scroll(true, "left", 0.0001);                // auto background scrolling
        lv1cloudTwoBg->scroll(true, "left", 0.0003);

        // Max's includes to scene
        // drawing and updating necessary objects
        hud->draw();
        hud->interact(player1->playerHealth);

        healthpack1->draw();
        healthpack1->interact(player1->player);
        healthpack2->draw();
        healthpack2->interact(player1->player);


        for(int i = 0; i < 5; i++)
        {
            mine1[i]->draw();
            mine1[i]->interact(player1->player);
        }

        for(int i = 0; i < 5; i++)
        {
            turret1[i]->draw();
            turret1[i]->interact(player1->player);
        }


        player1->draw();

        if(itemTimer->getTicks() > 120)
        {
            player1->animate();
            healthpack1->animate();
            healthpack2->animate();
            for(int i = 0; i < 5; i++)
            {
                mine1[i]->animate();
            }
            for(int i = 0; i < 5; i++)
            {
                turret1[i]->animate();
            }

            itemTimer->resetTime();
        }

        player1->interact(healthpack1->healthpack);
        player1->interact(healthpack2->healthpack);
        for(int i = 0; i < 5; i++)
        {
            player1->interact(mine1[i]->mine);
        }

        for(int i = 0; i < 5; i++)
        {
            player1->interact(turret1[i]->turrethead);

            player1->interact(turret1[i]->turretbullet);
        }

        //Eric's drawings
        if(wpns->action == wpns->PISTOL)
        {
            pistol->vel = 0.2;
            pistol->weaponDmg = 10;
            pistol->projScale.x = 0.2;
            pistol->projScale.y = 0.2;
            wpns = pistol;
        }
        if(wpns->action == wpns->GRENADELAUNCHER)
        {
            grenadelauncher->vel = 0.075;
            grenadelauncher->accel = 0.01;
            grenadelauncher->weaponDmg = 25;
            grenadelauncher->projScale.x = 0.2;
            grenadelauncher->projScale.y = 0.2;
            wpns = grenadelauncher;
        }
        if(wpns->action == wpns->BEAM)
        {
            laserGun->vel = 0.3;
            laserGun->weaponDmg = 50;
            laserGun->projScale.x = 0.2;
            laserGun->projScale.y = 0.2;
            wpns = laserGun;
        }
        if(wpns->action == wpns->SHOCKRIFLE)
        {
            shockRifle->vel = 0.4;
            shockRifle->weaponDmg = 100;
            shockRifle->projScale.x = 0.3;
            shockRifle->projScale.y = 0.15;
            wpns = shockRifle;

            shockBulOne->vel = 0.4;
            shockBulOne->weaponDmg = 100;
            shockBulOne->projScale.x = 0.3;
            shockBulOne->projScale.y = 0.15;

            shockBulTwo->vel = 0.4;
            shockBulTwo->weaponDmg = 100;
            shockBulTwo->projScale.x = 0.3;
            shockBulTwo->projScale.y = 0.15;
        }

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, wpns->proj->tex);
        wpns->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulOne->proj->tex);
        shockBulOne->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulTwo->proj->tex);
        shockBulTwo->drawProj();
        glBindTexture(GL_TEXTURE_2D, grenadeBoom->proj->tex);
        grenadeBoom->drawProj();

        glBindTexture(GL_TEXTURE_2D, pistol->weaponSkin->tex);
        pistol->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, grenadelauncher->weaponSkin->tex);
        grenadelauncher->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, laserGun->weaponSkin->tex);
        laserGun->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, shockRifle->weaponSkin->tex);
        shockRifle->drawWeapon();

        //Drawing and bullet actions----------------------------
        if(timer->getTicks() > 15)
        {
            wpns->weaponAction(player1->player);
            if(wpns->action == wpns->SHOCKRIFLE)
            {
                shockBulOne->weaponAction(player1->player);
                shockBulTwo->weaponAction(player1->player);
            }
            for(int i = 0; i < 5; i++)
            {
                if(col->projHit(wpns, mine1[i]->mine))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    mine1[i]->health -= wpns->weaponDmg;
                    if(mine1[i]->health <= 0)
                    {
                        mine1[i]->mine->obj.pos.z = -9.0;
                        mine1[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine1[i]->mine, grenadelauncher, 1);
                        shockRifle->weaponSpawn(mine1[i]->mine, shockRifle, 2);
                    }
                }
            }
            for(int i = 0; i < 5; i++)
            {
                if(col->projHit(wpns, turret1[i]->turrethead))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    turret1[i]->health -= wpns->weaponDmg;
                    if(turret1[i]->health <= 0)
                    {
                        turret1[i]->turrethead->obj.pos.z = -9.0;
                        turret1[i]->turretbarrel->obj.pos.z = -9.0;
                        turret1[i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret1[i]->turrethead, laserGun, 1);
                        shockRifle->weaponSpawn(turret1[i]->turrethead, shockRifle, 2);
                    }

                }
            }
            for(int i = 0; i < 5; i++)
            {
                if(col->projHit(shockBulOne, mine1[i]->mine) || col->projHit(shockBulTwo, mine1[i]->mine))
                {
                    mine1[i]->health -= shockBulOne->weaponDmg;
                    if(mine1[i]->health <= 0)
                    {
                        mine1[i]->mine->obj.pos.z = -9.0;
                        mine1[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine1[i]->mine, grenadelauncher, 1);
                        shockRifle->weaponSpawn(mine1[i]->mine, shockRifle, 2);
                    }
                }

                if(col->projHit(shockBulOne, turret1[i]->turrethead) || col->projHit(shockBulTwo, turret1[i]->turrethead))
                {
                    turret1[i]->health -= shockBulOne->weaponDmg;
                    if(turret1[i]->health <= 0)
                    {
                        turret1[i]->turrethead->obj.pos.z = -9.0;
                        turret1[i]->turretbarrel->obj.pos.z = -9.0;
                        turret1[i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret1[i]->turrethead, laserGun, 1);
                        shockRifle->weaponSpawn(turret1[i]->turrethead, shockRifle, 2);
                    }
                }
            }
            grenadelauncher->weaponFall();
            laserGun->weaponFall();
            shockRifle->weaponFall();
            timer->resetTime();
        }
        glPopMatrix();
        //End of Eric's Drawings --------------------------------------------

        if(player1->killCount == 10)
        {
            pistol->onlyOnceP == 0;
            grenadelauncher->onlyOnceG == 0;
            laserGun->onlyOnceB == 0;
            shockRifle->onlyOnceS == 0;

            state = levelTwo;
            player1->killCount = 0;
            doneLoading = false;
            for(int i = 0; i < 5; i++)
            {
                delete mine1[i];
                delete turret1[i];
            }
            mine1.clear();
            turret1.clear();
        }
    }

    if(state == levelTwo)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // change this if you want to change color of scene
        glLoadIdentity();

        //LevelThree background
        //sky
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2skyBg->plxTexture->tex);
        lv2skyBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //bottom clouds
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2cloudOneBg->plxTexture->tex);
        lv2cloudOneBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //air
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2airBg->plxTexture->tex);
        lv2airBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //big mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2bigMountainBg->plxTexture->tex);
        lv2bigMountainBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //medium mountain
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2mediumMountainBg->plxTexture->tex);
        lv2mediumMountainBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //sky clouds top
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2cloudTwoBg->plxTexture->tex);
        lv2cloudTwoBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //small mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2smallMountainBg->plxTexture->tex);
        lv2smallMountainBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //stars
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2starsBg->plxTexture->tex);
        lv2starsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //ground
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv2groundBg->plxTexture->tex);
        lv2groundBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        //clouds effect auto scrolling
        lv2cloudOneBg->scroll(true, "left", 0.0001);                // auto background scrolling
        lv2cloudTwoBg->scroll(true, "left", 0.0003);
        lv2starsBg->scroll(true, "left", 0.00001);

        // Max's includes to scene
        // drawing and updating necessary objects
        hud->draw();
        hud->interact(player1->playerHealth);

        healthpack1->draw();
        healthpack1->interact(player1->player);
        healthpack2->draw();
        healthpack2->interact(player1->player);


        for(int i = 0; i < 10; i++)
        {
            mine2[i]->draw();
            mine2[i]->interact(player1->player);
        }

        for(int i = 0; i < 10; i++)
        {
            turret2[i]->draw();
            turret2[i]->interact(player1->player);
        }


        player1->draw();

        if(itemTimer->getTicks() > 120)
        {
            player1->animate();
            healthpack1->animate();
            healthpack2->animate();
            for(int i = 0; i < 10; i++)
            {
                mine2[i]->animate();

                turret2[i]->animate();
            }

            itemTimer->resetTime();
        }

        player1->interact(healthpack1->healthpack);
        player1->interact(healthpack2->healthpack);
        for(int i = 0; i < 10; i++)
        {
            player1->interact(mine2[i]->mine);

            player1->interact(turret2[i]->turrethead);

            player1->interact(turret2[i]->turretbullet);
        }

        //Eric's drawings
        if(wpns->action == wpns->PISTOL)
        {
            pistol->vel = 0.2;
            pistol->weaponDmg = 10;
            pistol->projScale.x = 0.2;
            pistol->projScale.y = 0.2;
            wpns = pistol;
        }
        if(wpns->action == wpns->GRENADELAUNCHER)
        {
            grenadelauncher->vel = 0.075;
            grenadelauncher->accel = 0.01;
            grenadelauncher->weaponDmg = 25;
            grenadelauncher->projScale.x = 0.2;
            grenadelauncher->projScale.y = 0.2;
            wpns = grenadelauncher;
        }
        if(wpns->action == wpns->BEAM)
        {
            laserGun->vel = 0.3;
            laserGun->weaponDmg = 50;
            laserGun->projScale.x = 0.2;
            laserGun->projScale.y = 0.2;
            wpns = laserGun;
        }
        if(wpns->action == wpns->SHOCKRIFLE)
        {
            shockRifle->vel = 0.4;
            shockRifle->weaponDmg = 100;
            shockRifle->projScale.x = 0.3;
            shockRifle->projScale.y = 0.15;
            wpns = shockRifle;

            shockBulOne->vel = 0.4;
            shockBulOne->weaponDmg = 100;
            shockBulOne->projScale.x = 0.3;
            shockBulOne->projScale.y = 0.15;

            shockBulTwo->vel = 0.4;
            shockBulTwo->weaponDmg = 100;
            shockBulTwo->projScale.x = 0.3;
            shockBulTwo->projScale.y = 0.15;
        }
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, wpns->proj->tex);
        wpns->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulOne->proj->tex);
        shockBulOne->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulTwo->proj->tex);
        shockBulTwo->drawProj();
        glBindTexture(GL_TEXTURE_2D, grenadeBoom->proj->tex);
        grenadeBoom->drawProj();

        glBindTexture(GL_TEXTURE_2D, pistol->weaponSkin->tex);
        pistol->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, grenadelauncher->weaponSkin->tex);
        grenadelauncher->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, laserGun->weaponSkin->tex);
        laserGun->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, shockRifle->weaponSkin->tex);
        shockRifle->drawWeapon();

        //Drawing and bullet actions----------------------------
        if(timer->getTicks() > 15)
        {
            wpns->weaponAction(player1->player);
            if(wpns->action == wpns->SHOCKRIFLE)
            {
                shockBulOne->weaponAction(player1->player);
                shockBulTwo->weaponAction(player1->player);
            }
            for(int i = 0; i < 10; i++)
            {
                if(col->projHit(wpns, mine2[i]->mine))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    mine2[i]->health -= wpns->weaponDmg;
                    if(mine2[i]->health <= 0)
                    {
                        mine2[i]->mine->obj.pos.z = -9.0;
                        mine2[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine2[i]->mine, grenadelauncher, 2);
                        shockRifle->weaponSpawn(mine2[i]->mine, shockRifle, 2);
                    }
                }
            }
            for(int i = 0; i < 10; i++)
            {
                if(col->projHit(wpns, turret2[i]->turrethead))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    turret2[i]->health -= wpns->weaponDmg;
                    if(turret2[i]->health <= 0)
                    {
                        turret2[i]->turrethead->obj.pos.z = -9.0;
                        turret2[i]->turretbarrel->obj.pos.z = -9.0;
                        turret2[i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret2[i]->turrethead, laserGun, 2);
                        shockRifle->weaponSpawn(turret2[i]->turrethead, shockRifle, 2);
                    }
                }
            }
            for(int i = 0; i < 10; i++)
            {
                if(col->projHit(shockBulOne, mine2[i]->mine) || col->projHit(shockBulTwo, mine2[i]->mine))
                {
                    mine2[i]->health -= shockBulOne->weaponDmg;
                    if(mine2[i]->health <= 0)
                    {
                        mine2[i]->mine->obj.pos.z = -9.0;
                        mine2[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine2[i]->mine, grenadelauncher, 2);
                        shockRifle->weaponSpawn(mine2[i]->mine, shockRifle, 2);
                    }
                }

                if(col->projHit(shockBulOne, turret2[i]->turrethead) || col->projHit(shockBulTwo, turret2[i]->turrethead))
                {
                    turret2[i]->health -= shockBulOne->weaponDmg;
                    if(turret2[i]->health <= 0)
                    {
                        turret2[i]->turrethead->obj.pos.z = -9.0;
                        turret2[i]->turretbarrel->obj.pos.z = -9.0;
                        turret2[i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret2[i]->turrethead, laserGun, 2);
                        shockRifle->weaponSpawn(turret2[i]->turrethead, shockRifle, 2);
                    }
                }
            }
            grenadelauncher->weaponFall();
            laserGun->weaponFall();
            shockRifle->weaponFall();
            timer->resetTime();
        }
        glPopMatrix();
        //End of Eric's Drawings --------------------------------------------

        if(player1->killCount == 20)
        {
            pistol->onlyOnceP == 0;
            grenadelauncher->onlyOnceG == 0;
            laserGun->onlyOnceB == 0;
            shockRifle->onlyOnceS == 0;

            state = levelThree;
            player1->killCount = 0;
            doneLoading = false;

            for(int i = 0; i < 10; i++)
            {
                delete mine2[i];
                delete turret2[i];
            }
            mine2.clear();
            turret2.clear();

        }
    }

    if(state == levelThree)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // change this if you want to change color of scene
        glLoadIdentity();

        //LevelOne background
        //sky
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOskyBg->plxTexture->tex);
        lvOskyBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //sky clouds top
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOcloudTwoBg->plxTexture->tex);
        lvOcloudTwoBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //fog
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOfogBg->plxTexture->tex);
        lvOfogBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //big mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvObigMountainsBg->plxTexture->tex);
        lvObigMountainsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOmountainBG->plxTexture->tex);
        lvOmountainBG->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //bottom clouds
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOcloudOneBg->plxTexture->tex);
        lvOcloudOneBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //small mountains
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lvOsmallMountainsBg->plxTexture->tex);
        lvOsmallMountainsBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();
        //ground
        glPushMatrix();
        glScalef(3.33, 3.33, 1.0);
        glBindTexture(GL_TEXTURE_2D, lv0groundBg->plxTexture->tex);
        lv0groundBg->renderBack(screenWidth, screenHeight);
        glPopMatrix();

        //firstPlatform->draw();
        //firstPlatform->interact(player1->player);

        //clouds effect auto scrolling
        lvOcloudOneBg->scroll(true, "left", 0.0001);                // auto background scrolling
        lvOcloudTwoBg->scroll(true, "left", 0.0003);

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, backBtn->backBtnTex->tex);
        backBtn->drawButton(4.7,3.4,-1.0,0.5,0.3,1.0);
        glPopMatrix();

        // Max's includes to scene
        // drawing and updating necessary objects
        hud->draw();
        hud->interact(player1->playerHealth);

        healthpack1->draw();
        healthpack1->interact(player1->player);
        healthpack2->draw();
        healthpack2->interact(player1->player);


        for(int i = 0; i < 15; i++)
        {
            mine3[i]->draw();
            mine3[i]->interact(player1->player);

            turret3[i]->draw();
            turret3[i]->interact(player1->player);
        }


        player1->draw();

        if(itemTimer->getTicks() > 120)
        {
            player1->animate();
            healthpack1->animate();
            healthpack2->animate();
            for(int i = 0; i < 15; i++)
            {
                mine3[i]->animate();

                turret3[i]->animate();
            }

            itemTimer->resetTime();
        }

        player1->interact(healthpack1->healthpack);
        player1->interact(healthpack2->healthpack);
        for(int i = 0; i < 15; i++)
        {
            player1->interact(mine3[i]->mine);

            player1->interact(turret3[i]->turrethead);

            player1->interact(turret3[i]->turretbullet);
        }

        //Eric's drawings
        if(wpns->action == wpns->PISTOL)
        {
            pistol->vel = 0.2;
            pistol->weaponDmg = 10;
            pistol->projScale.x = 0.2;
            pistol->projScale.y = 0.2;
            wpns = pistol;
        }
        if(wpns->action == wpns->GRENADELAUNCHER)
        {
            grenadelauncher->vel = 0.075;
            grenadelauncher->accel = 0.01;
            grenadelauncher->weaponDmg = 25;
            grenadelauncher->projScale.x = 0.2;
            grenadelauncher->projScale.y = 0.2;
            wpns = grenadelauncher;
        }
        if(wpns->action == wpns->BEAM)
        {
            laserGun->vel = 0.3;
            laserGun->weaponDmg = 50;
            laserGun->projScale.x = 0.2;
            laserGun->projScale.y = 0.2;
            wpns = laserGun;
        }
        if(wpns->action == wpns->SHOCKRIFLE)
        {
            shockRifle->vel = 0.4;
            shockRifle->weaponDmg = 100;
            shockRifle->projScale.x = 0.3;
            shockRifle->projScale.y = 0.15;
            wpns = shockRifle;

            shockBulOne->vel = 0.4;
            shockBulOne->weaponDmg = 100;
            shockBulOne->projScale.x = 0.3;
            shockBulOne->projScale.y = 0.15;

            shockBulTwo->vel = 0.4;
            shockBulTwo->weaponDmg = 100;
            shockBulTwo->projScale.x = 0.3;
            shockBulTwo->projScale.y = 0.15;
        }
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, wpns->proj->tex);
        wpns->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulOne->proj->tex);
        shockBulOne->drawProj();
        glBindTexture(GL_TEXTURE_2D, shockBulTwo->proj->tex);
        shockBulTwo->drawProj();
        glBindTexture(GL_TEXTURE_2D, grenadeBoom->proj->tex);
        grenadeBoom->drawProj();

        glBindTexture(GL_TEXTURE_2D, pistol->weaponSkin->tex);
        pistol->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, grenadelauncher->weaponSkin->tex);
        grenadelauncher->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, laserGun->weaponSkin->tex);
        laserGun->drawWeapon();
        glBindTexture(GL_TEXTURE_2D, shockRifle->weaponSkin->tex);
        shockRifle->drawWeapon();

        //Drawing and bullet actions----------------------------
        if(timer->getTicks() > 15)
        {
            wpns->weaponAction(player1->player);
            if(wpns->action == wpns->SHOCKRIFLE)
            {
                shockBulOne->weaponAction(player1->player);
                shockBulTwo->weaponAction(player1->player);
            }
            for(int i = 0; i < 15; i++)
            {
                if(col->projHit(wpns, mine3[i]->mine))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    mine3[i]->health -= wpns->weaponDmg;
                    if(mine3[i]->health <= 0)
                    {
                        mine3[i]->mine->obj.pos.z = -9.0;
                        mine3[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine3[i]->mine, grenadelauncher, 3);
                        shockRifle->weaponSpawn(mine3[i]->mine, shockRifle, 5);
                    }
                }
            }
            for(int i = 0; i < 15; i++)
            {
                if(col->projHit(wpns, turret3[i]->turrethead))
                {
                    if(wpns->action != wpns->SHOCKRIFLE)
                    {
                        wpns->hitToOrigin(player1->player);
                    }
                    turret3[i]->health -= wpns->weaponDmg;
                    if(turret3[i]->health <= 0)
                    {
                        turret3[i]->turrethead->obj.pos.z = -9.0;
                        turret3[i]->turretbarrel->obj.pos.z = -9.0;
                        turret3[i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret3[i]->turrethead, laserGun, 3);
                        shockRifle->weaponSpawn(turret3[i]->turrethead, shockRifle, 5);
                    }
                }
            }
            for(int i = 0; i < 15; i++)
            {
                if(col->projHit(shockBulOne, mine3[i]->mine) || col->projHit(shockBulTwo, mine3[i]->mine))
                {
                    mine3[i]->health -= shockBulOne->weaponDmg;
                    if(mine3[i]->health <= 0)
                    {
                        mine3[i]->mine->obj.pos.z = -9.0;
                        mine3[i]->mine->obj.exist = false;
                        grenadelauncher->weaponSpawn(mine3[i]->mine, grenadelauncher, 3);
                        shockRifle->weaponSpawn(mine3[i]->mine, shockRifle, 5);
                    }
                }

                if(col->projHit(shockBulOne, turret3[i]->turrethead) || col->projHit(shockBulTwo, turret3[i]->turrethead))
                {
                    turret3[i]->health -= shockBulOne->weaponDmg;
                    if(turret3[i]->health <= 0)
                    {
                        turret3[i]->turrethead->obj.pos.z = -9.0;
                        turret3 [i]->turretbarrel->obj.pos.z = -9.0;
                        turret3 [i]->turrethead->obj.exist = false;
                        laserGun->weaponSpawn(turret3[i]->turrethead, laserGun, 3);
                        shockRifle->weaponSpawn(turret3[i]->turrethead, shockRifle, 5);
                    }
                }
            }
            grenadelauncher->weaponFall();
            laserGun->weaponFall();
            shockRifle->weaponFall();
            timer->resetTime();
        }
        glPopMatrix();
        //End of Eric's Drawings --------------------------------------------

        if(player1->killCount == 30)
        {

            state = credit;
            player1->killCount = 0;
            doneLoading = false;
            for(int i = 0; i < 15; i++)
            {
                delete mine3[i];
                delete turret3[i];
            }
            pistol->onlyOnceP == 0;
            grenadelauncher->onlyOnceG == 0;
            laserGun->onlyOnceB == 0;
            shockRifle->onlyOnceS == 0;
            mine3.clear();
            turret3.clear();

            _glScene();
            _glScene::initGL();

        }
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

    glOrtho(-5.0, 5.0, -3.5, 3.5, 0.1, 100);  // will readjust game view to match game window size

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
            if(state == levelOne)
            {
                kbMS->moveEnv(lv1groundBg, .005);
                kbMS->moveEnv(lv1mountainsBg, .0045);
                kbMS->moveEnv(lv1forestBg, .0048);
                kbMS->moveEnv(lv1bigMountainBg, .002);
            }
            if(state == levelTwo)
            {
                kbMS->moveEnv(lv2groundBg, .005);
                kbMS->moveEnv(lv2smallMountainBg, .0048);
                kbMS->moveEnv(lv2mediumMountainBg, .0045);
                kbMS->moveEnv(lv2bigMountainBg, .002);
            }
            if(state == levelThree)
            {
                kbMS->moveEnv(lv0groundBg, .005);
                kbMS->moveEnv(lvOmountainBG, .0045);
                kbMS->moveEnv(lvOsmallMountainsBg, .0048);
                kbMS->moveEnv(lvObigMountainsBg, .002);
                kbMS->moveObj(firstPlatform->platform, 0.06);
            }
            if(state != menu)
            {
                kbMS->keyPressed(snds);
            }

            //Max's additions to scene
            kbMS->movePly(player1, 0.030);                  // will flip player in said direction and translate the desired direciton
            kbMS->moveObj(healthpack1->healthpack, inRelationToPlayer);  // healthpacks move at speed given
            kbMS->moveObj(healthpack2->healthpack, inRelationToPlayer);
            if(state == levelOne)
            {
                for(int i = 0; i < 5; i++)
                {
                    kbMS->moveObj(mine1[i]->mine, inRelationToPlayer);
                    kbMS->moveObj(turret1[i]->turretParts, inRelationToPlayer);
                    kbMS->moveObj(turret1[i]->turretbullet, inRelationToPlayer);
                }
            }
            if(state == levelTwo)
            {
                for(int i = 0; i < 10; i++)
                {
                    kbMS->moveObj(mine2[i]->mine, inRelationToPlayer);
                    kbMS->moveObj(turret2[i]->turretParts, inRelationToPlayer);
                    kbMS->moveObj(turret2[i]->turretbullet, inRelationToPlayer);
                }
            }
            if(state == levelThree)
            {
                for(int i = 0; i < 15; i++)
                {
                    kbMS->moveObj(mine3[i]->mine, inRelationToPlayer);
                    kbMS->moveObj(turret3[i]->turretParts, inRelationToPlayer);
                    kbMS->moveObj(turret3[i]->turretbullet, inRelationToPlayer);
                }
            }

            //-----------

            //Eric's keyboard inputs
            kbMS->keyPressed(shockBulOne);
            kbMS->keyPressed(shockBulTwo);
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

            }

            if(posmX > -0.49 && posmX < 0.49 && posmY >-2.25 && posmY < -1.78)
            {

                std::exit(0);

            }
        }

        if(state == help)
        {


            if(posmX > -0.49 && posmX < 0.49 && posmY >-1.76 && posmY < -1.25)
            {
                state = menu;

                doneLoading = false;
            }
        }

        if(state == credit)
        {

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
            if(player1->playerHealth >= 0){
                kbMS->anglesForShots(wpns, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotOne(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotTwo(shockBulTwo, LOWORD(lParam), HIWORD(lParam));
                if(wpns->action == wpns->SHOCKRIFLE)
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam) ); //For shockRifle;
                    kbMS->mouseDown(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                    kbMS->mouseDown(shockBulTwo, LOWORD(lParam), HIWORD(lParam));//
                }
                else
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam));//for weapons other than shockRifle
                }
            }
        }

        if(state == levelTwo)
        {
            if(posmX > 4.42 && posmX < 5.0 && posmY > 3.24 && posmY < 3.5)
            {
                state = menu;

                doneLoading = false;
            }

            if(player1->playerHealth >= 0){
                kbMS->anglesForShots(wpns, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotOne(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotTwo(shockBulTwo, LOWORD(lParam), HIWORD(lParam));
                if(wpns->action == wpns->SHOCKRIFLE)
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam) ); //For shockRifle;
                    kbMS->mouseDown(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                    kbMS->mouseDown(shockBulTwo, LOWORD(lParam), HIWORD(lParam));//
                }
                else
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam));//for weapons other than shockRifle
                }
            }
        }

        if(state == levelThree)
        {
            if(posmX > 4.42 && posmX < 5.0 && posmY > 3.24 && posmY < 3.5)
            {
                state = menu;

                doneLoading = false;
            }

            if(player1->playerHealth >= 0){
                kbMS->anglesForShots(wpns, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotOne(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                kbMS->anglesForShockShotTwo(shockBulTwo, LOWORD(lParam), HIWORD(lParam));
                if(wpns->action == wpns->SHOCKRIFLE)
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam) ); //For shockRifle;
                    kbMS->mouseDown(shockBulOne, LOWORD(lParam), HIWORD(lParam));
                    kbMS->mouseDown(shockBulTwo, LOWORD(lParam), HIWORD(lParam));//
                }
                else
                {
                    kbMS->mouseDown(wpns, LOWORD(lParam), HIWORD(lParam));//for weapons other than shockRifle
                }
            }
        }

        break;
    }

    case WM_RBUTTONDOWN:
    {

        //Eric's additons
        GetOGLPos(LOWORD(lParam), HIWORD(lParam));
        if(levelOne)
        {
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

        break;
    }

    case WM_MOUSEWHEEL:
    {
        break;
    }

    }
}

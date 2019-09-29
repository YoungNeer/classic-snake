#include "snake.h"

Snake::Snake()
{
    mEatBuffer.loadFromFile("assets/audio/eat.ogg");
    mEatSound.setBuffer(mEatBuffer);

    mLoseBuffer.loadFromFile("assets/audio/lose.ogg");
    mLoseSound.setBuffer(mLoseBuffer);

    mBodyTexture.loadFromFile("assets/images/snake segments/segment_body.png");
    mBodySprite.setTexture(mBodyTexture);

    reset();
}
Snake::~Snake(){}


void Snake::reset()
{
    mBody.clear();
    mBody.push_back(SnakeSegment(22,15));
    mBody.push_back(SnakeSegment(21,15));
    mBody.push_back(SnakeSegment(20,15));
    setDirection(Direction::None);
    mSpeed=15;
    mLost=false;
    mScore=0;
    mLives=3;
}


void Snake::growSnake(){
    if (mBody.empty()) return;
    SnakeSegment& tail = mBody.back();

    if (mBody.size()>1){
        SnakeSegment& tailBone = mBody.at(mBody.size()-2);
        if (tail.position.x==tailBone.position.x)
            if (tail.position.y>tailBone.position.y)
                mBody.push_back(SnakeSegment(tail.position.x,tail.position.y+1));
            else
                mBody.push_back(SnakeSegment(tail.position.x,tail.position.y-1));
        else
            if (tail.position.x>tailBone.position.x)
                mBody.push_back(SnakeSegment(tail.position.x+1,tail.position.y));
            else
                mBody.push_back(SnakeSegment(tail.position.x-1,tail.position.y));
    }
    else
        if (mDir==Direction::Up)
            mBody.push_back(SnakeSegment(tail.position.x,tail.position.y-1));
        else if (mDir==Direction::Down)
            mBody.push_back(SnakeSegment(tail.position.x,tail.position.y+1));
        else if (mDir==Direction::Left)
            mBody.push_back(SnakeSegment(tail.position.x-1,tail.position.y));
        else if (mDir==Direction::Right)
            mBody.push_back(SnakeSegment(tail.position.x+1,tail.position.y));
}

void Snake::update(HUD &hud){
    if (mBody.empty() or mDir==Direction::None) return;
    move();
    checkCollision(hud);
}

void Snake::move(){
    if (mLost) return;
    for (int i=mBody.size()-1;i>0;--i)
        mBody.at(i).position=mBody.at(i-1).position;

    SnakeSegment& head=mBody.front();
    if (mDir==Direction::Up)
        head.position.y-=1;
    else if (mDir==Direction::Down)
        head.position.y+=1;
    else if (mDir==Direction::Right)
        head.position.x+=1;
    else if (mDir==Direction::Left)
        head.position.x-=1;
}

void Snake::checkCollision(HUD &hud){
    //It's impossible for the snake to collide if #segments<5
    if (mBody.size()<5) return;

    SnakeSegment& head=mBody.front();

    for (auto itr=mBody.begin()+1;itr!=mBody.end();++itr)
        if (itr->position == head.position){
            cut(mBody.end()-itr,hud);
            return;
        }
}

void Snake::cut(int l_segments,HUD &hud){
    for (int i=0;i<l_segments;++i)
        mBody.pop_back();
    mLives-=1;
    hud.setLives(mLives);
    if (not mLives) lose();
    else mLoseSound.play();
}

void Snake::incrementScore(HUD &hud)
{
    mScore+=1;
    hud.setScore(mScore);
    mEatSound.play();
}

sf::Vector2i Snake::getPosition(){
    return (mBody.empty() ? sf::Vector2i(1,1) : mBody.front().position);
}

void Snake::setDirection(Direction lDir){
    mDir=lDir;
}

int Snake::getLives(){
    return mLives;
}

int Snake::getScore(){
    return mScore;
}

Direction Snake::getDirection(){
    return mDir;
}

bool Snake::hasLost(){
    return mLost;
}

void Snake::render(Window &l_win){

//    mHeadSprite.setPosition(sf::Vector2f(mBody.front().position)*static_cast<float>(TILE_SIZE));
//    l_win.draw(mHeadSprite);

    for (sf::Uint8 i=0;i<mBody.size();++i){
        mBodySprite.setPosition(64+mBody[i].position.x*TILE_SIZE,80+mBody[i].position.y*TILE_SIZE);
        l_win.draw(mBodySprite);
    }

//    mTailSprite.setPosition(sf::Vector2f(mBody.back().position)*static_cast<float>(TILE_SIZE));
//    l_win.draw(mTailSprite);

}

void Snake::toggleLost(){
    mLost=not mLost;
}

void Snake::lose(){
    mLost=true;
    mLoseSound.play();
}

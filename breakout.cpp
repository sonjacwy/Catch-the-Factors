#include "breakout.h"
#include <QPainter>
#include <QApplication>
#include <string>
#include <QString>
#include <iostream>
#include <ctime>

using namespace std;

Breakout::Breakout(QWidget *parent): QWidget(parent){

  setFocusPolicy(Qt::StrongFocus);
  x = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  caughtshort= FALSE;
  line_double = FALSE;
  caughtmonster = FALSE;
  score=0;
  level=1;
  lives=3;

  oneup = new OneUp();

  line = new Line();
  shortline= new ShortLine();
  longline= new LongLine();
  fullline = new FullLine();
  doubleline = new Line();
  doubleline->setState(line->getRect().x()+100);

  longer= new Longer();
  shorter= new Shorter();
  drop = new Drop();
  bomb = new Bomb();
  star = new Star();
  devil = new Devil();
  monster = new Monster();
  doub = new Double();
  mon = new Mon();

  nextlevel = new NextLevel();
  dropnumber = new Number();
  numdropped = false;
  caughtdevil = false;
  
  srand(time(0));
  number = (rand()%99)+10; // Generate a random number for reference

  while (!CheckPrime(number)){ // to check if the number generated is a prime number
	number = (rand()%99)+10;}


  srand(time(0));
  i= (rand()%2+1);
 
  setPalette(QPalette(QColor(250, 250, 200, 127)));
  setAutoFillBackground(true);

  setDrop();

}

Breakout::~Breakout() { //Destructor
 delete line;
 delete drop;

}

void Breakout::setDrop(){ //Return true if the Longer icon is 
	srand(time(0));
	
	int num= rand()%9;

	if (num==0)
		drop = longer;

	else if (num==1)
		drop = shorter;

	else if (num==2)
		drop = oneup;

	else if (num==3)
		drop = bomb;

	else if (num==4)
		drop = nextlevel;

	else if (num==5)
		drop = star;

	else if (num==6)
		drop = devil;

	else if (num==7)
		drop = mon;

	else if (num==8)
		drop = doub;

}

void Breakout::paintEvent(QPaintEvent *event){
  QPainter painter(this);

  if (gameOver) { // print an error message when game is over i.e. the player loses all his lives (in progress)
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over Press Start Key to replay");
  }

  else if(gameWon) {  //Print a victory message when the player wins
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory :)");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory :)");
  }

  else { // Print the line image
	if (i==1){ //Randomly generate an object to be dropped
		painter.drawImage(drop->getRect(), drop->getImage());
		numdropped = false;}

	else {	
		painter.drawText(dropnumber->getRect(), dropnumber->getNumber()); //Dropping numbers
		numdropped = true;}

 	painter.drawImage(line->getRect(), line->getImage()); //Displaying the line

	if (line_double){ //If the double option is caught, gerneate another line to be displayed
		painter.drawImage(doubleline->getRect(), doubleline->getImage());}

	if (caughtmonster){ // If the monster icon is caught, display the monster that follows the line
		painter.drawImage(monster->getRect(), monster->getImage());}

  }
}

void Breakout::timerEvent(QTimerEvent *event){ 
	caughtshort = FALSE;

	if (caughtmonster)
		monster->autoMove(line->getRect().x());

	if (numdropped){	
		dropnumber->autoMove(level);

		if (checknumCollision())
			caughtshort=TRUE;}

	else{
		drop->autoMove(level,line->getRect().x()-20);

		if (checkdropCollision())
			caughtshort=TRUE;}

  	repaint();
}

void Breakout::keyPressEvent(QKeyEvent *event){
   if (!caughtdevil){
    switch (event->key()) {
    case Qt::Key_Left:	{  
         		int x= line->getRect().x();
        		for (int i=1; i<=5; i++)
          		line->moveLeft(x-5);
			if (line_double){
				int y= doubleline->getRect().x();
        			for (int i=1; i<=5; i++)
					doubleline->moveLeft(y-5);}
        		break;
       			}
    case Qt::Key_Right:	{ 
          		int x = line->getRect().x();
          		for (int i=1; i<=5; i++)
           			 line->moveRight(x+5);

			if (line_double){
				int y= doubleline->getRect().x();
        			for (int i=1; i<=5; i++)
					doubleline->moveRight(y+5);}

       			 }
       			 break;
    case Qt::Key_P:{ 
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }}

   else {
    switch (event->key()) {
    case Qt::Key_Right:	{  
         		int x= line->getRect().x();
        		for (int i=1; i<=5; i++)
          		line->moveLeft(x-3);
			


			if (line_double){
				int y= doubleline->getRect().x();
        			for (int i=1; i<=5; i++)
					doubleline->moveLeft(y-3);}

        		break;
       			}
    case Qt::Key_Left:	{ 
          		int x = line->getRect().x();
          		for (int i=1; i<=5; i++)
           			 line->moveRight(x+2);

			if (line_double){
				int y= doubleline->getRect().x();
        			for (int i=1; i<=5; i++)
					doubleline->moveRight(y+2);}

       			 }
       			 break;
    case Qt::Key_P:{ 
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }}
}

void Breakout::startGame(){ //function for resetting when game starts
  if (!gameStarted) {
    ResetLine();
    line->resetState();
    drop->resetState(line->getRect().x());
    dropnumber->resetState();
    
    score = 0;
    level = 1;
    lives = 3;
    i = (rand()%2+1);
    number = (rand()%99)+10;
    

    setPalette(QPalette(QColor(250, 250, 200, 127)));
    setAutoFillBackground(true);

    gameOver = FALSE; 
    gameWon = FALSE; 
    gameStarted = TRUE;
    line_double = FALSE;
    emit scoreChanged(score);
    emit levelChanged(level);
    emit livesChanged(lives);
    emit numberChanged(number);
    timerId = startTimer(10);  
  }
}

void Breakout::pauseGame(){
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); 
   }
}

void Breakout::stopGame(){
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
  lives=3;
  level=1;
  score=0;

}

void Breakout::victory(){
  killTimer(timerId);
  gameWon = TRUE;  
  gameStarted = FALSE;
}

bool Breakout::checkdropCollision() // check if the objects are caught by the line (in progress)
{
	bool caught=false;


  if (drop->getRect().bottom() > 400){
	setDrop();
	drop->resetState(line->getRect().x());
	srand(time(0));
 	i= (rand()%2+1);}

if (!line_double){
  if ((drop->getRect()).intersects(line->getRect())){
		caught=true;
		
		if (drop==longer){ // make the line longer if the longer icon is caught
			line=longline;
			score+=10;
			emit scoreChanged(score);}

		else if (drop == shorter){ // make the line shorter if the shorter icon is caugh  
			line=shortline;
			score+=10;
			emit scoreChanged(score);}

		else if (drop == bomb){ // Reduce the number of lives 
			lives--;
			emit livesChanged(lives);		
			score-=10;
			emit scoreChanged(score);}
	
		else if (drop == oneup){ // Increase the number of lives
			score+=100;
			emit scoreChanged(score);
			lives++;
			emit livesChanged(lives);}

		else if (drop == nextlevel){ // Move to the next level
			score+=50;
			emit scoreChanged(score);
			level++;
			emit levelChanged(level);
			if (level ==2){ // Change the background to indicate the change of level
				setPalette(QPalette(QColor(0, 200, 0, 127)));
				setAutoFillBackground(true);}

			else if (level ==3){ // Change the background to indicate the change in level
				setPalette(QPalette(QColor(200,0, 0, 127)));
				setAutoFillBackground(true);}
}

		else if (drop == star){ //Make the line as long as the window width
			score+=50;
			emit scoreChanged(score);
			caughtmonster = FALSE;
			if (line != fullline){
			line = fullline;}

			else if (line == fullline)
			ResetLine();}

		else if (drop == devil){ //Make a flag to indicate the devil is caught
			score -=50;
			emit scoreChanged(score);
			caughtdevil = true;}

		else if (drop == doub){ //Make a flag to indicate the double line option is caught
			score+=50;
			emit scoreChanged(score);
			line_double = TRUE;}

		else if (drop == mon){ //Display the monster when the monster icon is caught
			score-=50;
			emit scoreChanged(score);
			caughtmonster = true;
			monster->setState(0);}
			
		if (lives == 0) //Check if the player loses all the lives, stop the game when he/ she does
			stopGame();

		else{
			setDrop(); //Randomly generate another item to be dropped
			drop->resetState(line->getRect().x()); //.reset the position to be dropped from
			srand(time(0));
 			i= (rand()%2+1);}}
	ChangeLevel();} // Check the score to change levels appropriately

else{ // When there is a double line
	  if ((drop->getRect()).intersects(line->getRect()) || (drop->getRect()).intersects(doubleline->getRect())){
		caught=true;
		
		if (drop==longer){ // make the line longer if the longer icon is caught
			line=longline;
			score+=10;
			emit scoreChanged(score);
			caughtmonster = FALSE;}

		else if (drop == shorter){ // make the line shorter if the shorter icon is caugh  
			line=shortline;
			score+=10;
			emit scoreChanged(score);
			caughtmonster = FALSE;}

		else if (drop == bomb){
			lives--;
			emit livesChanged(lives);		
			score-=10;
			emit scoreChanged(score);}
	
		else if (drop == oneup){
			score+=100;
			emit scoreChanged(score);
			lives++;
			emit livesChanged(lives);
			caughtmonster = FALSE;}

		else if (drop == nextlevel){
			score+=50;
			emit scoreChanged(score);
			level++;
			emit levelChanged(level);
			caughtmonster = FALSE;
			if (level ==2){
				setPalette(QPalette(QColor(0, 200, 0, 127)));
				setAutoFillBackground(true);}

			else if (level ==3){
				setPalette(QPalette(QColor(200,0, 0, 127)));
				setAutoFillBackground(true);}
}

		else if (drop == star){
			score+=50;
			emit scoreChanged(score);
			caughtmonster = FALSE;
			if (line != fullline){
			line = fullline;}

			else if (line == fullline)
			ResetLine();
			
				
				}

		else if (drop == devil){
			score -=50;
			emit scoreChanged(score);
			caughtdevil = true;}

		else if (drop == doub){
			score+=50;
			emit scoreChanged(score);
			caughtmonster = FALSE;
			line_double = TRUE;}
			
		if (lives == 0)
			stopGame();

		else{
			setDrop();
			drop->resetState(line->getRect().x());
			srand(time(0));
 			i= (rand()%2+1);}}
	ChangeLevel();}
	
	return caught;
}

bool Breakout::checknumCollision() // check if the objects are caught by the line (in progress)
{
	bool caught=false;


  if (dropnumber->getRect().bottom() > 400){
		dropnumber->setdropNum();
		dropnumber->resetState();
		srand(time(0));
  		i= (rand()%2+1);}

if (caughtmonster && (dropnumber->getRect()).intersects(monster->getRect()) && number%(dropnumber->getNum()) == 0){ //Reduce the score when the monster caught the right number
		score-=10;
		emit scoreChanged(score);

		caught=true;		

		dropnumber->setdropNum();
		dropnumber->resetState();}

else{ 

if (!line_double){ 
  if ((dropnumber->getRect()).intersects(line->getRect()) && number%(dropnumber->getNum()) == 0){ // Check if the number caught is a factor of the number shown
		score+=10;
		emit scoreChanged(score);

		caught=true;		

		dropnumber->setdropNum();
		dropnumber->resetState();}

	else if ((dropnumber->getRect()).intersects(line->getRect()) && number% (dropnumber->getNum())!=0){ // When it is not a factor, reduce the score
		score-=10;
		emit scoreChanged(score);
	
		lives--;
		emit livesChanged(lives);

		caught=true;

		
		if (lives == 0)
			stopGame();

		else{ // Randomly generate another number to be dropped			
			dropnumber->setdropNum();
			dropnumber->resetState();
			srand(time(0));
  			i= (rand()%2+1);}}

ChangeLevel();}


else{//When there is a double line
 if ((dropnumber->getRect()).intersects(line->getRect()) && number%(dropnumber->getNum()) == 0){
		score+=10;
		emit scoreChanged(score);

		caught=true;		

		dropnumber->setdropNum();
		dropnumber->resetState();}

 	else if ((dropnumber->getRect()).intersects(line->getRect()) && number% (dropnumber->getNum())!=0){
		score-=10;
		emit scoreChanged(score);
	
		lives--;
		emit livesChanged(lives);

		caught=true;

		
		if (lives == 0)
			stopGame();

		else{			
			dropnumber->setdropNum();
			dropnumber->resetState();
			srand(time(0));
  			i= (rand()%2+1);}}

	else if ((dropnumber->getRect()).intersects(doubleline->getRect()) && number%(dropnumber->getNum()) == 0){
		score+=10;
		emit scoreChanged(score);

		caught=true;		

		dropnumber->setdropNum();
		dropnumber->resetState();}

	else if ((dropnumber->getRect()).intersects(doubleline->getRect()) && number% (dropnumber->getNum())!=0){
		score-=10;
		emit scoreChanged(score);
	
		lives--;
		emit livesChanged(lives);

		caught=true;

		
		if (lives == 0)
			stopGame();

		else{			
			dropnumber->setdropNum();
			dropnumber->resetState();
			srand(time(0));
  			i= (rand()%2+1);}}
}
ChangeLevel();}

return caught;
}

void Breakout::ChangeLevel(){ //Check the score and change to the corresponding level
	if (score >100)
		level =2;

	else if (score > 200)
		level = 3;

	else if (score > 300)
		victory();

	if (level ==2){
		setPalette(QPalette(QColor(0, 200, 0, 127)));
		setAutoFillBackground(true);}

	else if (level ==3){
		setPalette(QPalette(QColor(200,0, 0, 127)));
		setAutoFillBackground(true);}

}

bool Breakout::CheckPrime(int x){ // Check if the number generated for reference is a prime number
	bool flag = false;
	for (int i=2; i<x; i++){
		if(x%i==0){
			flag = true;
			break;}}

return flag;}

void Breakout::ResetLine(){ // Reset line back to its original length
	Line *temp;
	temp = new Line();
        line = temp;
}
		




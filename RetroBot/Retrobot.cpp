#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>
#include<windows.h>

#define ESC    	27
#define QtdRobos 9
#define QtdRobosPulando 8

/* variáveis globais */
int GlbLar, GlbAlt;
int GlbBtnLar, GlbBtnAlt;

/* funções usadas neste programa */
void TelaInicial();
void Creditos();
void Tela1();

  // Carrega os arquivos mp3
 // mciSendString("open .\\sons\\introCortado2.mp3 type MPEGVideo alias repetido", NULL, 0, 0); 
 // mciSendString("open .\\sons\\led.mp3 type MPEGVideo alias fundo", NULL, 0, 0);   
 // mciSendString("open .\\sons\\my.mp3 type MPEGVideo alias fundo2", NULL, 0, 0); 

void AlteraCorImg(unsigned char *P, int Tam, int Cor) {
  int i;
  for(i=0; i < Tam; i++)
    if (i > 23 and i % 4 < 3)
      P[i] = Cor;
}



void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam é o tamanho dos ponteiros da imagem e da máscara
// Img é o ponteiro que aponta para o vetor que contém a imagem capturada com getimage(..)
// Msk é o ponteiro que será transformado em máscara
  int i;
  unsigned char B, G, R;
  B = Img[24];
  G = Img[25];
  R = Img[26];
  for(i=24; i < Tam; i+=4) {
    if (Img[i]==B and Img[i+1]==G and Img[i+2]==R) {
      Img[i] = 0;
      Img[i+1] = 0;
      Img[i+2] = 0;
      Msk[i] = 255;
      Msk[i+1] = 255;
      Msk[i+2] = 255;
    }
    else {
      Msk[i] = 0;
      Msk[i+1] = 0;
      Msk[i+2] = 0;
      
    }
  }
}


int main() {
  GlbLar = 1280;
  GlbAlt = 720;
  GlbBtnLar = 250;
  GlbBtnAlt = 80;

  /* inicia área gráfica */
  initwindow(GlbLar, GlbAlt, "Esqueleto de jogo com tela inicial e créditos", 0, 0);
  /* transfere execução para a função TelaInicial() */
  
  //TelaInicial();
  Tela1();
  
  /* finaliza área gráfica */
  closegraph();
  return(0);
}

void TelaInicial() {
  bool Fim = false;
  int pg = 1;
  POINT P;
  HWND janela;
  
  bool btnJogarSelecionado = false; 
  bool btnCreditosSelecionado = false; 
  bool btnSairSelecionado = false;
  
  int tam;
  void *Fundo;
  void *btnJogar, *btnJogarSel;
  void *btnCreditos, *btnCreditosSel;
  void *btnSair, *btnSairSel;
  /* carga da imagem de fundo */
  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\ImgRetrobot.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  
  cleardevice();
  
  /* carga da imagem dos botões */
  cleardevice();
  tam = imagesize(0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  btnJogar = malloc(tam);
  readimagefile(".\\imagens\\btnjogar.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogar);
  btnJogarSel = malloc(tam);
  readimagefile(".\\imagens\\btnjogarsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogarSel);
  btnCreditos = malloc(tam);
  readimagefile(".\\imagens\\btncreditos.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditos);
  btnCreditosSel = malloc(tam);
  readimagefile(".\\imagens\\btncreditossel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditosSel);
  btnSair = malloc(tam);
  readimagefile(".\\imagens\\btnsair.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSair);
  btnSairSel = malloc(tam);
  readimagefile(".\\imagens\\btnsairsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSairSel);
  
  janela = GetForegroundWindow(); // Obtém o Handle da janela gráfica
  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    if (btnJogarSelecionado)
      putimage(900, 400, btnJogarSel, COPY_PUT); // retângulo do botão 900, 400, 900+GlbBtnLar-1, 400+GlbBtnAlt-1
    else
      putimage(900, 400, btnJogar, COPY_PUT);
    if (btnCreditosSelecionado)
      putimage(900, 500, btnCreditosSel, COPY_PUT);
    else
      putimage(900, 500, btnCreditos, COPY_PUT);
    if (btnSairSelecionado)
      putimage(900, 600, btnSairSel, COPY_PUT);
    else
      putimage(900, 600, btnSair, COPY_PUT);
      
    /*settextstyle(1, 0, 8);
    outtextxy(getmaxx() / 3, 100, "Retrobot");*/
      
    setvisualpage(pg);
    /* Verifica movimento do mouse independente de haver clique */
    if (GetCursorPos(&P)) // captura a posição do mouse. A variável P é carregada com coordenadas físicas de tela
      if (ScreenToClient(janela, &P)) { // Converte as coordenadas físicas de tela para as coordenadas 
  
        /* configura a troca da imagem do botão quando o mouse está sobre ele */
        btnJogarSelecionado = false; // botão jogar
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
          btnJogarSelecionado = true;
        btnCreditosSelecionado = false; // botão créditos
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
          btnCreditosSelecionado = true;
        btnSairSelecionado = false; // botão sair
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 600 <= P.y && P.y <= 600+GlbBtnAlt-1)
          btnSairSelecionado = true;

        /* verifica se o mouse foi pressionado na área de algum botão */          
        if(GetKeyState(VK_LBUTTON)&0x80) {
          // botão jogar
          if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
            Tela1();    
          // botão créditos
          else if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
            Creditos();
          // botão sair
          else if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 600 <= P.y && P.y <= 600+GlbBtnAlt-1)
            Fim = true;
        }
      }
  }  
}

void Creditos() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;
	
	

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\ImgCreditos.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    /*setbkcolor(0);
    settextstyle(1, 0, 8);
    outtextxy(getmaxx() / 3, 100, "Creditos");*/
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
    }
  }
}

void Tela1() {
	int pg = 1;
	char tecla = 0;
	char s[50];
	int  x, y, raio;
	double passox, passoy;
	x = 100;
	y = 100;
	raio = 18; 
	passox = 3;
	passoy = 1;
	strcpy(s, "pressione Esc para Sair");
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, SomPasso = false;
	int iRobo, i, iRoboPula, iSomAndar;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	
	int ELipse[6];
	
	void *Fundo;
	
	int tamEscada;
  
  	//char tecla = 0;
	int posXrobo = 100;
	int posYrobo = 100;
	int tam, tamFundo, xRobo, yRobo, tamCaixa;
	/*void *R;  // esta variável é um vetor dinâmico que contém o sprite
	void *RM; // esta variável é um vetor dinâmico que contém a máscara*/
	unsigned char *R[QtdRobos], *RM[QtdRobos];
	unsigned char *RE[QtdRobos], *REM[QtdRobos];
	unsigned char *C, *CM;
	unsigned char *PU[QtdRobosPulando], *PUM[QtdRobosPulando];
	unsigned char *PUE[QtdRobosPulando], *PUEM[QtdRobosPulando];
	unsigned char *Escada, *EscadaM;
	/*void **R[QtdRobos], **RM[QtdRobos];
	R = (void **)malloc(sizeof(void *) * QtdRobos);
	RM = (void **)malloc(sizeof(void *) * QtdRobos);*/
	void *T; //Img Fundo
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
  	
  	cleardevice();
  	
  	tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
	Fundo = malloc(tam);
  	readimagefile(".\\imagens\\Tela1.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  	
  	
  	
  	
  	
  	
  	
  	
  	tamEscada = imagesize(0, 0, 16, 115);
  	
  	tamFundo = imagesize(0, 0, 1280, 720);
	//tam = imagesize(0, 0, 149, 149);
  	
  	tam = imagesize(0, 0, 75, 90);
  	for(i = 0; i <= QtdRobos; i++)
  	{
  		/*R[i] = malloc(tam);
  		RM[i] = malloc(tam);*/
  		R[i] = (unsigned char *)malloc(tam);
  		RM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobos; i++)
  	{
  		RE[i] = (unsigned char *)malloc(tam);
  		REM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobos; i++)
  	{
  		PU[i] = (unsigned char *)malloc(tam);
  		PUM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobos; i++)
  	{
  		PUE[i] = (unsigned char *)malloc(tam);
  		PUEM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
	
	tamCaixa = imagesize(0, 0, 50, 50);
	C = (unsigned char *)malloc(tam);
  	CM = (unsigned char *)malloc(tam);
  	
  	
  	putimage(0, 0, Fundo, COPY_PUT);
  	
  	readimagefile(".\\imagens\\EscadaF1.bmp", 0, 0, 16, 115);
  	getimage(0, 0, 16, 115, Escada);
  	getimage(0, 0, 16, 115, EscadaM);
	
  	readimagefile(".\\imagens\\ParLD.bmp", 0, 0, 75, 90); // carrega a imagem
  	getimage(0, 0, 75, 90, R[0]); // captura para o ponteiro R
  	getimage(0, 0, 75, 90, RM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	/*tam = imagesize(0, 0, 99, 150);
  	R[1] = (unsigned char *)malloc(tam);
  	RM[1] = (unsigned char *)malloc(tam);*/
  	readimagefile(".\\imagens\\And1.bmp", 0, 0, 75, 90); 
  	getimage(0, 0, 75, 90, R[1]); 
  	getimage(0, 0, 75, 90, RM[1]);
  	
  	//tam = imagesize(0, 0, 70, 85);
  	readimagefile(".\\imagens\\And2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[2]); 
  	getimage(0, 0, 75, 90, RM[2]);
  	
  	readimagefile(".\\imagens\\And3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[3]); 
  	getimage(0, 0, 75, 90, RM[3]);
  	
  	readimagefile(".\\imagens\\And4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[4]); 
  	getimage(0, 0, 75, 90, RM[4]);
  	
  	readimagefile(".\\imagens\\And5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[5]); 
  	getimage(0, 0, 75, 90, RM[5]);
  	
  	readimagefile(".\\imagens\\And6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[6]); 
  	getimage(0, 0, 75, 90, RM[6]);
  	
  	readimagefile(".\\imagens\\And7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[7]); 
  	getimage(0, 0, 75, 90, RM[7]);
  	
  	readimagefile(".\\imagens\\And8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[8]); 
  	getimage(0, 0, 75, 90, RM[8]);
  	
  	
  	//Imgs Pra esquerda
  	
  	readimagefile(".\\imagens\\ParLE.bmp", 0, 0, 75, 90); // carrega a imagem
  	getimage(0, 0, 75, 90, RE[0]); // captura para o ponteiro R
  	getimage(0, 0, 75, 90, REM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	readimagefile(".\\imagens\\invAnd1.bmp", 0, 0, 75, 90); 
  	getimage(0, 0, 75, 90, RE[1]); 
  	getimage(0, 0, 75, 90, REM[1]);
  	
  	readimagefile(".\\imagens\\invAnd2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[2]); 
  	getimage(0, 0, 75, 90, REM[2]);
  	
  	readimagefile(".\\imagens\\invAnd3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[3]); 
  	getimage(0, 0, 75, 90, REM[3]);
  	
  	readimagefile(".\\imagens\\invAnd4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[4]); 
  	getimage(0, 0, 75, 90, REM[4]);
  	
  	readimagefile(".\\imagens\\invAnd5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[5]); 
  	getimage(0, 0, 75, 90, REM[5]);
  	
  	readimagefile(".\\imagens\\invAnd6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[6]); 
  	getimage(0, 0, 75, 90, REM[6]);
  	
  	readimagefile(".\\imagens\\invAnd7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[7]); 
  	getimage(0, 0, 75, 90, REM[7]);
  	
  	readimagefile(".\\imagens\\invAnd8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[8]); 
  	getimage(0, 0, 75, 90, REM[8]);
  	
  	
  	
  	readimagefile(".\\imagens\\Caixa.bmp", 0, 0, 50, 50);
  	getimage(0, 0, 50, 50, C);
  	getimage(0, 0, 50, 50, CM);
  	
  	
  	
  	readimagefile(".\\imagens\\Pul1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[0]);
  	getimage(0, 0, 75, 90, PUM[0]);
  	
  	readimagefile(".\\imagens\\Pul2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[1]);
  	getimage(0, 0, 75, 90, PUM[1]);
  	
  	readimagefile(".\\imagens\\Pul3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[2]);
  	getimage(0, 0, 75, 90, PUM[2]);
  	
  	readimagefile(".\\imagens\\Pul4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[3]);
  	getimage(0, 0, 75, 90, PUM[3]);
  	
  	readimagefile(".\\imagens\\Pul5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[4]);
  	getimage(0, 0, 75, 90, PUM[4]);
  	
  	readimagefile(".\\imagens\\Pul6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[5]);
  	getimage(0, 0, 75, 90, PUM[5]);
  	
  	readimagefile(".\\imagens\\Pul7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[6]);
  	getimage(0, 0, 75, 90, PUM[6]);
  	
  	readimagefile(".\\imagens\\Pul8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[7]);
  	getimage(0, 0, 75, 90, PUM[7]);
  	
  	
  	//Pulo Esqueda
  	
  	readimagefile(".\\imagens\\invPul1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[0]);
  	getimage(0, 0, 75, 90, PUEM[0]);
  	
  	readimagefile(".\\imagens\\invPul2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[1]);
  	getimage(0, 0, 75, 90, PUEM[1]);
  	
  	readimagefile(".\\imagens\\invPul3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[2]);
  	getimage(0, 0, 75, 90, PUEM[2]);
  	
  	readimagefile(".\\imagens\\invPul4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[3]);
  	getimage(0, 0, 75, 90, PUEM[3]);
  	
  	readimagefile(".\\imagens\\invPul5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[4]);
  	getimage(0, 0, 75, 90, PUEM[4]);
  	
  	readimagefile(".\\imagens\\invPul6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[5]);
  	getimage(0, 0, 75, 90, PUEM[5]);
  	
  	readimagefile(".\\imagens\\invPul7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[6]);
  	getimage(0, 0, 75, 90, PUEM[6]);
  	
  	readimagefile(".\\imagens\\invPul8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[7]);
  	getimage(0, 0, 75, 90, PUEM[7]);
  	
  	
  	putimage(0, 0, Fundo, COPY_PUT);
  	
  	cleardevice();
  	
  	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, RE[i], REM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, R[i], RM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PU[i], PUM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PUE[i], PUEM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	
	PreparaImg(tamEscada, Escada, EscadaM);
	//PreparaImg(tamCaixa, C, CM);
	//PreparaImg(tam, R[0], RM[0]); // configura as cores branca e preta em cada pixel para formar o recorte
	/*PreparaImg(tam, R[1], RM[1]);
	PreparaImg(tam, R[2], RM[2]);
	PreparaImg(tam, R[3], RM[3]);
	PreparaImg(tam, R[4], RM[4]);
	PreparaImg(tam, R[5], RM[5]);*/
  	
  	
  	iRobo = 0;
  	xRobo = 105;
	yRobo = 500 - 90;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iSomAndar = 0;

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
	    
	    /*readimagefile(".\\img\\predios.bmp", posXimg, 0, 1000, 600);
  		getimage(posXimg, 0, 1000, 600, T);*/
  		
		
		putimage(0, 0, Fundo, COPY_PUT);
		
		/*putimage(900, 550, EscadaM, AND_PUT);
		putimage(900, 550, Escada, OR_PUT);*/
		
		/*PosMag1[0] = 0;
		PosMag1[1] = 500;
		PosMag1[2] = getmaxx();
		PosMag1[3] = getmaxy();
		bar(PosMag1[0], PosMag1[1], PosMag1[2], PosMag1[3]);*/
		
		PosObs1[0] = 600;
		PosObs1[1] = 300;
		PosObs1[2] = 800;
		PosObs1[3] = 340;
		bar(PosObs1[0], PosObs1[1], PosObs1[2], PosObs1[3]);
		
		PosObs2[0] = 700;
		PosObs2[1] = 340;
		PosObs2[2] = 800;
		PosObs2[3] = 500;
		bar(PosObs2[0], PosObs2[1], PosObs2[2], PosObs2[3]);
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = ;
		PosObs3[2] = 800;
		PosObs3[3] = 500;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		ELipse[0] = 615;
		ELipse[1] = 340;
		ELipse[2] = 700;
		ELipse[3] = 340;
		ELipse[4] = 700;
		ELipse[5] = 438;
		fillpoly(3, ELipse);
		
		
		/*putimage(xRobo, yRobo, RM, AND_PUT);
    	putimage(xRobo, yRobo, R, OR_PUT);*/
    	
    	
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
    	
    	if(andaDireita == true)
    	{
    		/*ELipse[0] = 615;
			ELipse[1] = 340;
			ELipse[2] = 700;
			ELipse[3] = 340;
			ELipse[4] = 700;
			ELipse[5] = 438;*/
			if(pulaRobo == false)
			{
				putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
				putimage(xRobo, yRobo, R[iRobo], OR_PUT);
			}
			if(((xRobo + 75) >= 615 && (xRobo + 75) <= 700) && (yRobo <= 438 && yRobo >= 340))
			{
				//xRobo = 605;
				std::cout << "Entrououuu" << std::endl;
			}
			else{
				xRobo += 20;
				std::cout << "Entrououuu 2222222" << std::endl;
			}
			std::cout << xRobo << std::endl;
			iRobo++;
			iSomAndar++;
			if(iRobo >= QtdRobos){
				iRobo = 0; }
			delay(20);
			if(iSomAndar = iSomAndar%2){
				sndPlaySound(".\\sons\\som_passo.wav", SND_ASYNC);
			}
			
		}
		else if(andaEsquerda == true)
		{
			if(pulaRobo == false)
			{
				putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
				putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
			}
			if((xRobo - 10) <= 0 )
			{
				xRobo = -10;
			}
			else{
				xRobo -= 10;
			}
			iRobo++;
			if(iRobo >= QtdRobos){
				iRobo = 0; }
		}
		else
    	{
    		if(pulaRobo == false)
    		{
    			if(LadoRobo == 1)
	    		{
	    			putimage(xRobo, yRobo, RM[0], AND_PUT);
					putimage(xRobo, yRobo, R[0], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, REM[0], AND_PUT);
					putimage(xRobo, yRobo, RE[0], OR_PUT);
				}
			}
		}
		
		if(pulaRobo == true && iRoboPula >= 0)
		{
			std::cout << iRoboPula << std::endl;
			std::cout << yRobo << std::endl;
			/*for(i = 0; i < iRoboPula; i++)
			{*/
			
			//Efeito Sonoro Pulo
			if (iRoboPula == 1)
				sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);

			if(LadoRobo == 1)
			{
				putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
				putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
			}
			else if(LadoRobo == 0)
			{
				putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
				putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
			}
				//iRoboPula++;
			//}
			if(yRobo <=20)
			{
				yRobo = 10;
			}
			else if(yRobo >= 0)
			{
				if(iRoboPula >= 5)
				{
					yRobo += 20;
				}
				else
				{
					yRobo -= 20;
				}
			}
			iRoboPula++;
			if(iRoboPula > QtdRobosPulando){
				iRoboPula = 0;
				pulaRobo = false; }
			delay(10);
		}
    	
    	
    	//Controladores
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			//xRobo -= 10;
			andaEsquerda = true;
			LadoRobo = 0;
			 
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			andaDireita = true;
			LadoRobo = 1;
			
		}
    	if(GetKeyState(0x53)&0x80)   // S
    	{
    		//PiscaCaixa += 1;
    		if(yRobo + 90 < 490)
			{
	    		yRobo += 10;
    		}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W
    	{
    		pulaRobo = true;
    		if(iRoboPula == 0){ iRoboPula = 1; };
    	
		}
		if(GetKeyState(0x4b)&0x80)   // K
    	{
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L
    	{
    		//PiscaCaixa += 1;
		}
		
		/*if(yRobo + 90 < 490)
		{
			yRobo += 10;
		}
		else if()
		{
			
		}*/
		
		
		/*if(GetKeyState(VK_SPACE)&0x80) 
		{
			yRobo -= 50; 
		}*/
		
		
		setvisualpage(pg);
	
	    delay(100);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	
	free(R);
  	free(RM);
}


#include <inge9>
#include <ctime>
#include <cstdlib>

int main() {
  int atletaY = 0;
  int atletaX = 0;
  int virusY = 0;
  int virusX = 600;
  
  
  loadImage("background", "https://raw.githubusercontent.com/renaderibeiro/XoCorona/main/Imagens/background.png");
  loadImage("atleta", "https://raw.githubusercontent.com/renaderibeiro/XoCorona/main/Imagens/atleta.png");
  loadImage("virus", "https://raw.githubusercontent.com/renaderibeiro/XoCorona/main/Imagens/virus.png");
  waitUntilResourcesLoad();

  clear("black");
  drawText("XÔ CORONA!!",190, 180, 40, "white");
  drawText("Com a barra de espaço e as setas direita e esquerda", 90, 220, 20, "white");
  drawText("ajude o atleta a desviar do vírus SARS-CoV-2!! ", 140, 250, 20, "white");
    drawText("Pressione qualquer tecla para continuar", 180, 320, 16, "red");

  readKey();
  bool gameOver = false;
  
  while (!gameOver) {

    if (isKeyDown(" ")) {
	    atletaY = 1 - atletaY;
      clearKey(" ");
    }
    
    if (isKeyDown("ArrowLeft")) atletaX -=3;
    if (isKeyDown("ArrowRight")) atletaX +=3;
    
    virusX -= 4;
    

    drawImage("background", 0, 0);
    if (virusY == 0) {
      drawImage("virus", virusX, 240);
    } else {
      drawImage("virus", virusX, 120);
    }
    if (atletaY == 0) {
      drawImage("atleta", atletaX, 240);
    } else {
      drawImage("atleta", atletaX, 120);
    }
    
    if (atletaY == virusY && atletaX <= virusX + 60 && atletaX + 128 >= virusX) {
      gameOver = true;
    }
    
    if (virusX < 0) {
      virusY = rand() % 2;
      virusX = 600;
    }

    delay(30);
  }

  clear("red");
  drawText("O SARS-CoV-2 te pegou :(",100, 180, 40, "white");
  drawText("Esse é só um jogo mas na vida real", 130, 220, 24, "white");
  drawText("mantenha o isolamento social e espere a vacina!! ", 70, 250, 24, "white");
  
  return 0;
}
#include <inge9>
#include <ctime>
#include <cstdlib>

int main() {
  int atletaY = 0;
  int atletaX = 0;
  int virusY = 0;
  int virusX = 600;
  
  
  loadImage("background", "https://raw.githubusercontent.com/igorsouzacarvalho88/GameLabEduc/main/Imagens/background.png");
  loadImage("atleta", "https://raw.githubusercontent.com/igorsouzacarvalho88/GameLabEduc/main/Imagens/atleta.png");
  loadImage("virus", "https://raw.githubusercontent.com/igorsouzacarvalho88/GameLabEduc/main/Imagens/virus.png");
  
  clear("black");
  drawText("XÔ CORONA!!",190, 180, 40, "white");
  drawText("Com a barra de espaço e as setas direita e esquerda", 90, 220, 20, "white");
  drawText("ajude o atleta a desviar do COVID19!! ", 140, 250, 20, "white");
  
  delay(7000);
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
  drawText("O covid te pegou :(",150, 180, 40, "white");
  drawText("Esse é só um jogo mas na vida real", 130, 220, 24, "white");
  drawText("mantenha o isolamento social e espere a vacina!! ", 70, 250, 24, "white");
  
  return 0;
}
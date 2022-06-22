<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <title>Smashtec </title>
    <meta name="author" content=" Jefferson Silva, Leonel Araujo Brandão, Thayna Walckiers">
    <meta name="description" content=" SmashTEC">
    <meta name="keywords" content=" SmashTEC, jogo, PC, Luta, FATEC, Smashbros, Cancelados, Prova N2, Ferramentas Web">


</head>

<style>
  #container-imagem {
    position: fixed;
    height: 100vh;
    width: 100vw;
    z-index: -1; 
    background: url('https://i.pinimg.com/originals/b1/17/0e/b1170e74d9b4248eb188c155801d0973.jpg');
    background-size: cover;
  }
  h1{

    color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 30px;
    font-family: sans-serif;
    font-weight: bold;
    padding: 0;
    z-index: -1;
  }
  fieldset{
    color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 15px;
    font-family: sans-serif;
    font-weight: bold;
    padding: 0;
    z-index: -1;
  }
  </Style>
  <body>
  <div id="container-imagem"></div> 
    <nav class="navbar navbar-expand-lg navbar navbar-dark bg-dark">
      <div class="container-fluid">
        <a class="navbar-brand" href="Prova - Inicio.php"><img src="img/Smashtec_logo2.png"Width= 300 height=100></a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
          <ul class="navbar-nav me-auto mb-2 mb-lg-0">
            <li class="nav-item">
              <a class="nav-link" aria-current="page" href="Prova - Inicio.php">Inicio</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="Prova_Sobre.php">Sobre</a>
            </li>
          <a class="nav-link" href="Prova_Personagens.php">Personagens</a>
        </li>s
          <a class="nav-link" href="Prova_Discussão.php">Discussão</a>
        </li>   
        <a class="nav-link active" href="Prova_Contato.php">Reserve já</a>
      </li>   
            </li>
            <li class="nav-item">
              <a class="nav-link disabled">Jogar</a>
            </li>
          </ul>
          <form class="d-flex">
            <input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
            <button class="btn btn-outline-success" type="submit">Search</button>
          </form>
        </div>
      </div>
    </nav>

    <h1>Inscreva-se para receber uma versão beta antecipada</h1>
    <form action="index.html" method="GET"> 
        <fieldset>
            <legend>Dados do usuário</legend>
            <label for="nome">Nome</label><br>
            <input type="text" id="nome" name="nome" required><br>
            <label for="email">Email</label><br>
            <input type="email" id="email" name="email" required><br>
            <br><label for="sexo">Sexo</label><br>
            <input type="radio" name="sexo" value="masculino" id="masculino">
            <label for="masculino">Masculino</label>
            <input type="radio" name="sexo" value="feminino" id="feminino">
            <label for="feminino">Feminino</label><br>
            <input type="radio" name="sexo" value="nãoB" id="nãoB">
            <label for="nãoB">Não-Binário</label><br>

            <br><p>Qual Personagem você gostaria de jogar em SmashTEC?:</p>
            <input type="checkbox" name="modos" value="normal_retrobot" id="normal_retrobot">
            <label for="Retrobot">Retrobot</label><br>
            <input type="checkbox" name="modos" value="Wicca" id="Wicca">
            <label for="Wicca">Wicca</label><br>
            <input type="checkbox" name="modos" value="Medievicos" id="Medievicos">
            <label for="Medievicos">Medievicos Reis</label><br>
            <input type="checkbox" name="modos" value="Cuca" id="Cuca">
            <label for="Cuca">Cuca</label><br>
            <input type="checkbox" name="modos" value="outro" id="outro">
            <label for="outro">Outros...</label>
            <label for="mensagem">Escreva aqui...</label><br>
            <textarea id="mensagem" name="mensagem"
            rows="5" cols="33"></textarea><br>

            <input type="submit" value="Enviar">    
            <input type="reset" value="Limpar">
</body>
</html>


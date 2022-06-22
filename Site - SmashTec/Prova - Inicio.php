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
h1 {
    text-align: center;
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
h3 {

    color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 20px;
    font-family: sans-serif;
    font-weight: bold;
    padding: 0;
    z-index: -1;
}
h5 {

background-position: center;
margin: auto;
font-size: 30px;
font-family: sans-serif;
font-weight: bold;
padding: 0;
}

p {

    color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 15px;
    font-family: sans-serif;
    padding: 0;
    z-index: -1;
}
#cardtext{
  color: black  ;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 15px;
    font-family: sans-serif;
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
              <a class="nav-link active" aria-current="page" href="Prova - Inicio.php">Inicio</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="Prova_Sobre.php">Sobre</a>
            </li>
          <a class="nav-link" href="Prova_Personagens.php">Personagens</a>
        </li>s
          <a class="nav-link" href="Prova_Discussão.php">Discussão</a>
        </li>   
        <a class="nav-link" href="Prova_Contato.php">Reserve já</a>
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
    <section>
      <h1>SmashTEC</h1>
    <div class="d-flex justify-content-around">
        <div class="card" style="width: 18rem;">
          <img src="img/smashtec_card.png" class="card-img-top" alt="img-1">
          <div class="card-body">
            <h5 class="card-title">SmashTEC</h5>
            <p id="cardtext" class="card-text">É um jogo de luta e ação com crossovers na qual o jogador controla os personagens da franquia de jogos desenvolvidos pelos alunos da FATEC.</p> 
            <p id="cardtext" class="card-text">Lançamento previsto para Agosto de 2023 </p> 
            <a href="Prova_Sobre.php" class="btn btn-primary">Saiba mais</a>
          </div>
        </div>

        <div class="card" style="width: 18rem;">
          <div style="width:100%;height:0;padding-bottom:123%;position:relative;"><iframe src="https://giphy.com/embed/RSsdnOOSjiKg8NAzwj" width="100%" height="100%" style="position:absolute" frameBorder="0" class="giphy-embed" allowFullScreen></iframe></div><p>
          <div class="card-body">
            <h5 class="card-title">Personagens</h5>
            <p id="cardtext" class="card-text">Concept art dos personagens e modelagem 3D.</p>
            <a href="Prova_Personagens.php" class="btn btn-primary">Saiba mais</a>
          </div>
        </div>
        <div class="card" style="width: 18rem;">
          <img src="img/referencias.jpg" class="card-img-top" alt="img-1">
          <div class="card-body">
            <h5 class="card-title">Referencias</h5>
            <p id="cardtext" class="card-text">Referencias como Super Smash Bros, Playstation All Star Battle Royale, DON e Brawlout.</p>
            <a href="https://nintendoboy.com.br/2020/11/inspirados-em-super-smash-bros-conhecam-5-jogos-parecidos-com-a-serie-de-luta-da-nintendo/" target="_blank" class="btn btn-primary">Saiba mais</a>
          </div>
        </div>
      </div>



</body>
</html>


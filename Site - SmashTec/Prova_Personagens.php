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
ol{
  text-align: center;
      color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 20px;
    font-family: sans-serif;
    padding: 0;
    z-index: -1;}

  h2,h3{
      text-align: center;
      color: white;
    background-position: center;
    background-repeat: no-repeat;
    margin: auto;
    font-size: 30px;
    font-family: sans-serif;
    padding: 0;
    z-index: -1;}

    #carouselExampleCaptions{
      width: 1000px;
      left: 300px;
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
          <a class="nav-link active" href="Prova_Personagens.php">Personagens</a>
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

    <div id="carouselExampleCaptions" class="carousel slide" data-bs-ride="carousel">
      <div class="carousel-indicators">
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="1" aria-label="Slide 2"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="2" aria-label="Slide 3"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="3" aria-label="Slide 4"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="4" aria-label="Slide 5"></button>
      </div>
      <div class="carousel-inner">
        <div clas="row">
        <div class="carousel-item active">
          <img src="img/Retrobot_T_Frente.png" class="d-block w-100" alt="Retrobot3D">
          <div class="carousel-caption d-none d-md-block">
            <h5>Retrobot</h5>
            <p>Personagem criado pelo Grupo 3 no projeto do segundo semestre do curso..</p>
          </div>
        </div>
        <div class="carousel-item">
          <img src="img/wicca.jpeg" class="d-block w-100" alt="Wicca">
          <div class="carousel-caption d-none d-md-block">
            <h5>Wicca</h5>
            <p>Personagem criado pelo Grupo 3 no projeto do terceiro semestre do curso - Arte criada por @yukio.arts.</p>
          </div>
        </div>
        <div class="carousel-item">
          <img src="img/medievico.jpeg" class="d-block w-100" alt="Medievico">
          <div class="carousel-caption d-none d-md-block">
            <h5>Medievico Reis</h5>
            <p>Personagem criado pelo Grupo 3 no projeto do primeiro semestre do curso - Arte criada por @yukio.arts.</p>
          </div>
        </div>
        <div class="carousel-item">
          <img src="img/Cuca.jpeg" class="d-block w-100" alt="blastoise">
          <div class="carousel-caption d-none d-md-block">
            <h5>Cuca</h5>
            <p>Personagem criado pelo grupo do projeto Folks Journey  - Arte criada por @yukio.arts.</p>
          </div>
        </div>
          </div>
        </div>
      </div>
      <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="prev">
        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Previous</span>
      </button>
      <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="next">
        <span class="carousel-control-next-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Next</span>
      </button>
    </div>

      <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

<br><h3>Confira abaixo a lista de personagens confirmados</h3>
    <ol id="lista_personagens">
       <li>Retrobot</li> 
       <li>Medievico</li>
       <li>Wicca</li>
       <li>Cuca</li>
    </ol>

</body>
</html>


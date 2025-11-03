-- Cria o banco de dados
CREATE DATABASE IF NOT EXISTS app_db CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;

-- Cria o usuário do banco (mude a senha conforme necessário)
CREATE USER IF NOT EXISTS 'app_user'@'%' IDENTIFIED BY '123456';


-- Dá permissão total no banco para o usuário
GRANT ALL PRIVILEGES ON app_db.* TO 'app_user'@'%';
FLUSH PRIVILEGES;

-- Seleciona o banco
USE app_db;

-- Cria a tabela de usuários
CREATE TABLE IF NOT EXISTS usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario VARCHAR(50) NOT NULL UNIQUE,
    senha VARCHAR(255) NOT NULL,
    criado_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

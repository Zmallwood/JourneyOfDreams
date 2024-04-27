sudo -u postgres psql <<"__END__"
CREATE DATABASE journeyofdreams;
\c journeyofdreams;
CREATE TABLE accounts (
  id SERIAL PRIMARY KEY,
  username VARCHAR (50) UNIQUE NOT NULL,
  passwordHash INT NOT NULL
);
INSERT INTO accounts (username, passwordHash)
VALUES ('test', 0);
__END__

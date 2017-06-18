--Execute esse comando para popular o banco de dados
--apenas uma parte dos elementos livro é inserida aqui, estes dados são apenas para teste
----------------------------------------------------------------------------------------------------------------------------------------
--Create tables
CREATE TABLE "equipamento" (
	"id" serial NOT NULL,
	"nome" text NOT NULL,
	"peso" real NOT NULL,
	PRIMARY KEY ("id") ,
	CONSTRAINT "eq_nome" UNIQUE ("nome")
);
CREATE TABLE "rac_classes" (
	"c_id" integer NOT NULL,
	"r_id" integer NOT NULL,
	PRIMARY KEY ("r_id", "c_id") 
);
CREATE TABLE "rac_habilidades" (
	"r_id" integer NOT NULL,
	"h_id" integer NOT NULL,
	PRIMARY KEY ("r_id", "h_id") 
);
CREATE TABLE "cla_habilidades" (
	"c_id" integer NOT NULL,
	"h_id" integer NOT NULL,
	PRIMARY KEY ("c_id", "h_id") 
);
CREATE TABLE "hab_gerais" (
	"h_id" integer,
	PRIMARY KEY ("h_id") 
);
CREATE TABLE "m_equip" (
	"p_id" integer NOT NULL,
	"e_id" integer NOT NULL,
	"quantidade" int NOT NULL,
	"n_usando" int NOT NULL,
	PRIMARY KEY ("p_id", "e_id") 
);	
CREATE TABLE "m_hab" (
	"p_id" integer NOT NULL,
	"h_id" integer NOT NULL,
	PRIMARY KEY ("p_id", "h_id") 
);
CREATE TABLE "personagem" (
	"id" serial NOT NULL,
	"personagem" text NOT NULL,
	"jogador" text NOT NULL,
	"experiencia" integer NOT NULL,
	"nivel" integer NOT NULL,
	"mana_max" integer NOT NULL,
	"mana" integer NOT NULL,
	"motivacao" text NOT NULL,
	"vida" integer NOT NULL,
	"vida_max" integer NOT NULL,
	"raca" integer NOT NULL,
	"classe" integer NOT NULL,
	"atributos" integer[4] NOT NULL,
	"defesa" integer[3] NOT NULL,
	"carga" integer[3] NOT NULL,
	PRIMARY KEY ("id") 
);
COMMENT ON COLUMN "personagem"."atributos" IS '0-forca, 1-agilidade, 2-inteligencia, 3-vontade';
COMMENT ON COLUMN "personagem"."defesa" IS '1-bloqueio, 2-esquiva, 3-determinacao';
COMMENT ON COLUMN "personagem"."carga" IS '0-basica, 1-pesada, 2-maxima';
CREATE TABLE "habilidade" (
	"id" serial NOT NULL,
	"nome" text NOT NULL,
	"tipo" integer NOT NULL,
	"bonus" text NOT NULL,
	"req_nivel" integer NOT NULL,
	PRIMARY KEY ("id") ,
	CONSTRAINT "hb_nome" UNIQUE ("nome")
);
COMMENT ON COLUMN "habilidade"."tipo" IS '0-acao, 1-reacao, 2-suporte';
CREATE TABLE "raca" (
	"id" serial NOT NULL,
	"nome" text NOT NULL,
	"atributos" integer[4] NOT NULL,
	PRIMARY KEY ("id") ,
	CONSTRAINT "rc_nome" UNIQUE ("nome")
);
COMMENT ON COLUMN "raca"."id" IS '0-forca, 1-agilidade, 2-inteligencia, 3-vonade';
CREATE TABLE "classe" (
	"id" serial NOT NULL,
	"nome" text NOT NULL,
	"atributos" integer[4] NOT NULL,
	PRIMARY KEY ("id") ,
	CONSTRAINT "cl_nome" UNIQUE ("nome")
);COMMENT ON COLUMN "classe"."id" IS '0-forca, 1-agilidade, 2-inteligencia, 3-vonade';
--FOREIGN KEYs
ALTER TABLE "m_hab" ADD CONSTRAINT "mh_pr" FOREIGN KEY ("p_id") REFERENCES "personagem" ("id");
ALTER TABLE "m_equip" ADD CONSTRAINT "me_pr" FOREIGN KEY ("p_id") REFERENCES "personagem" ("id");
ALTER TABLE "m_equip" ADD CONSTRAINT "fk_m_equip_equipamento_1" FOREIGN KEY ("e_id") REFERENCES "equipamento" ("id");
ALTER TABLE "m_hab" ADD CONSTRAINT "fk_m_hab_equipamento_copy_2_1" FOREIGN KEY ("h_id") REFERENCES "habilidade" ("id");
ALTER TABLE "rac_classes" ADD CONSTRAINT "fk_rac_classes_raca_1" FOREIGN KEY ("r_id") REFERENCES "raca" ("id");
ALTER TABLE "rac_classes" ADD CONSTRAINT "fk_rac_classes_classe_1" FOREIGN KEY ("c_id") REFERENCES "classe" ("id");
ALTER TABLE "rac_habilidades" ADD CONSTRAINT "fk_rac_habilidades_raca_1" FOREIGN KEY ("r_id") REFERENCES "raca" ("id");
ALTER TABLE "rac_habilidades" ADD CONSTRAINT "fk_rac_habilidades_habilidade_1" FOREIGN KEY ("h_id") REFERENCES "habilidade" ("id");
ALTER TABLE "hab_gerais" ADD CONSTRAINT "fk_hab_gerais_habilidade_1" FOREIGN KEY ("h_id") REFERENCES "habilidade" ("id");
ALTER TABLE "cla_habilidades" ADD CONSTRAINT "fk_cla_habilidades_classe_1" FOREIGN KEY ("c_id") REFERENCES "classe" ("id");
ALTER TABLE "cla_habilidades" ADD CONSTRAINT "fk_cla_habilidades_habilidade_1" FOREIGN KEY ("h_id") REFERENCES "habilidade" ("id");
ALTER TABLE "personagem" ADD CONSTRAINT "fk_personagem_raca_1" FOREIGN KEY ("raca") REFERENCES "raca" ("id");
ALTER TABLE "personagem" ADD CONSTRAINT "fk_personagem_classe_1" FOREIGN KEY ("classe") REFERENCES "classe" ("id");



----------------------------------------------------------------------------------------------------------------------------------------
--Insere racas
INSERT INTO public.raca(nome, atributos) VALUES ('Anão', '{4,2,3,3}');	--forca, agilidade, inteligencia, vontade
INSERT INTO public.raca(nome, atributos) VALUES ('Elfo', '{2,4,3,3}');
INSERT INTO public.raca(nome, atributos) VALUES ('Humano', '{3,3,3,3}');

--exemplos:
--SELECT id, nome, atributos[1],atributos[2],atributos[3],atributos[4] FROM raca;
--SELECT * FROM classe WHERE classe.id IN (SELECT c_id FROM req_raca WHERE r_id = (SELECT raca.id FROM raca WHERE nome = 'Humano'));
--SELECT * FROM habilidade WHERE habilidade.id IN (SELECT h_id FROM hab_gerais)
--	OR habilidade.id IN (SELECT h_id FROM rac_habilidades WHERE r_id = (SELECT raca.id FROM raca WHERE nome = 'Humano'))
--	OR habilidade.id IN (SELECT h_id FROM cla_habilidades WHERE c_id = (SELECT classe.id FROM classe WHERE nome = 'Bardo'));
--SELECT "public".equipamentos."id" FROM "public".equipamentos WHERE EXISTS (SELECT m_equip.e_id FROM m_equip WHERE m_equip.p_id = 1)



----------------------------------------------------------------------------------------------------------------------------------------
--Insere classes
INSERT INTO public.classe(nome, atributos) VALUES ('Bardo',      '{0,1,0,1}');
INSERT INTO public.classe(nome, atributos) VALUES ('Druida',     '{0,0,1,1}');
INSERT INTO public.classe(nome, atributos) VALUES ('Espadachim', '{1,1,0,0}');

--ligações de racas e classes
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Anão')   );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT raca.id FROM raca WHERE raca.nome = 'Elfo')   );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Elfo')   );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );



----------------------------------------------------------------------------------------------------------------------------------------
--Insere habilidade
--gerais
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Atletismo',        2, '+2 em testes de correr, escalar, nadar, se equilibrar, prender o fôlego ou qualquer outra atividade que exija força fisica e coordenação motora', 1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Nanismo',          2, '+1d6 em testes para se esconder, se mover em silencio, ou passar despercebido de qualquer forma', 0);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Vontade de Ferro', 2, '+20 de vida', 5);
INSERT INTO hab_gerais(h_id) VALUES ((SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Atletismo')       );
INSERT INTO hab_gerais(h_id) VALUES ((SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Nanismo')         );
INSERT INTO hab_gerais(h_id) VALUES ((SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Vontade de Ferro'));

--racas
	--anao
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Forjado a fogo', 2, 'Resistencia ao fogo e visão e respiração não afetados pelo fogo', 1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Estabilidade',   2, '+1d6 em todos os testes de evitar quedas e manter o equilibrio',  1);
	--elfo
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Arborícola',     2, '+2 em todos os seus testes para se mover em silencio, se esconder e se movimentar em cima de uma arvore', 1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Raça florestal', 2, 'Quando estiver dentro de uma floresta, bosque ou selva você recebe +2 em todos os seus testes',           1);
	--humano
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Barganha', 2, '+1d6 em todos testes que envolvam comercio e outras negociações',                      1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Sorte',    1, 'Rola mais uma vez um dado cujo resultado seja 1. Só pode ser usado uma vez por turno', 1);
--ligações entre raças e habilidades
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Anão'),   (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Forjado a fogo'));
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Anão'),   (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Estabilidade')  );
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Elfo'),   (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Arborícola')    );
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Elfo'),   (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Raça florestal'));
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Humano'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Barganha')      );
INSERT INTO rac_habilidades(r_id, h_id) VALUES ((SELECT raca.id FROM raca WHERE raca.nome = 'Humano'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Sorte')         );

--classes
	--bardo
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Canção Exultante',   0, 'Todos seus aliados que puderem ouvir recebem +1 em todos os testes enquanto você continuar a tocar essa musica', 1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Furtivo',            2, '+1d6 em testes para se mover em silencio, se esconder, camuflar ou usar disfarces',                              1);
	--druida
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Determinar Magia',   0, 'Dif. 8. Concentrando-se nos fluxos de energias, você pode enxergar a aura de objetos mágicos, Runas Arcanas e Selos Místicos', 1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Sabedoria Selvagem', 2, '+1d6 em testes que envolvam a natureza como forragear, rastrear, encontrar abrigo, indentificar ervas, etc',                   1);
	--espadachim
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Acrobata',           2, '+1d6 em testes de equilíbrio, salto, piruetas e qualquer outra tentativa de se deslocar que exija coordenação, flexibilidade e precisão',  1);
INSERT INTO habilidade(nome, tipo, bonus, req_nivel) VALUES ('Combate Tático',     2, 'Se você derrubar um oponente comum ataque corporal, você pode imediatamente realizar outro ataque corporal (mas não Habilidades de Ação)', 1);
--ligações entre classes e habilidades
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Canção Exultante')  );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Furtivo')           );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Determinar Magia')  );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Sabedoria Selvagem'));
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Acrobata')          );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Combate Tático')    );

--exemplo: adiciona habilidades ao personagem 1 para testes
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 3);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 8);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 9);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 15);



----------------------------------------------------------------------------------------------------------------------------------------
--Insere equipamento
INSERT INTO equipamento (nome, peso) VALUES ('Adaga', 0.25);
INSERT INTO equipamento (nome, peso) VALUES ('Bordão', 2);
INSERT INTO equipamento (nome, peso) VALUES ('Espada Curta', 1);
INSERT INTO equipamento (nome, peso) VALUES ('Espada Longa', 2);
INSERT INTO equipamento (nome, peso) VALUES ('Machado de Batalha', 3);
INSERT INTO equipamento (nome, peso) VALUES ('Arco', 1.5);
INSERT INTO equipamento (nome, peso) VALUES ('flexa', 0.05);
INSERT INTO equipamento (nome, peso) VALUES ('Besta', 3);
INSERT INTO equipamento (nome, peso) VALUES ('virote', 0.04);
INSERT INTO equipamento (nome, peso) VALUES ('Plumbata', 0.05);
INSERT INTO equipamento (nome, peso) VALUES ('Armadura de Couro', 12);
INSERT INTO equipamento (nome, peso) VALUES ('Armadura de Batalha', 27);
INSERT INTO equipamento (nome, peso) VALUES ('Escudo medio', 6);
INSERT INTO equipamento (nome, peso) VALUES ('Escudo de Corpo', 9);
INSERT INTO equipamento (nome, peso) VALUES ('Cajado', 2);
INSERT INTO equipamento (nome, peso) VALUES ('Varinha', 0.15);
INSERT INTO equipamento (nome, peso) VALUES ('Simbolo Sagrado', 0.1);
INSERT INTO equipamento (nome, peso) VALUES ('Poção Antidoto', 0.12);
INSERT INTO equipamento (nome, peso) VALUES ('Poção da Explosão', 0.12);
INSERT INTO equipamento (nome, peso) VALUES ('Poção da Restauração', 0.12);
INSERT INTO equipamento (nome, peso) VALUES ('Poção de Mana', 0.12);
INSERT INTO equipamento (nome, peso) VALUES ('Poção de Vida', 0.12);

--adiciona equipamentos ao personagem 1 para testes
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 1, 1, 0);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 6, 1, 1);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 7, 23, 23);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 3, 1, 0);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 13, 1, 0);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 11, 1, 1);
--INSERT INTO m_equip(p_id, e_id, quantidade, n_usando) VALUES (1, 22, 3, 0);



----------------------------------------------------------------------------------------------------------------------------------------
--Insere personagem, pode ser feito direto peo programa
--INSERT INTO personagem 
--	(personagem, jogador, motivacao, experiencia, nivel, mana_max, mana, vida_max, vida, raca, classe, atributos, defesa, carga)
--    VALUES ('Ruff', 'Alemao', 'Matar', 3, 7, 90, 80, 140, 135, 3, 3, '{3, 2, 0, 0}', '{7, 3, 5}', '{7, 3, 5}')

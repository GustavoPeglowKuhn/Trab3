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
);

COMMENT ON COLUMN "classe"."id" IS '0-forca, 1-agilidade, 2-inteligencia, 3-vonade';


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


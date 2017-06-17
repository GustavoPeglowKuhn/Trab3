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

INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Canção Exultante')  );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Furtivo')           );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Determinar Magia')  );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Sabedoria Selvagem'));
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Acrobata')          );
INSERT INTO cla_habilidades(c_id, h_id) VALUES ((SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT habilidade.id FROM habilidade WHERE habilidade.nome = 'Combate Tático')    );


--adiciona habilidades ao personagem 1 para testes
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 3);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 8);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 9);
--INSERT INTO m_hab(p_id, h_id) VALUES (1, 15);

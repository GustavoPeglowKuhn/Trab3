INSERT INTO public.raca(nome, atributos) VALUES ('Anão', '{4,2,3,3}');	--forca, agilidade, inteligencia, vontade
INSERT INTO public.raca(nome, atributos) VALUES ('Elfo', '{2,4,3,3}');
INSERT INTO public.raca(nome, atributos) VALUES ('Humano', '{3,3,3,3}');

--SELECT id, nome, atributos[1],atributos[2],atributos[3],atributos[4] FROM raca;
--SELECT * FROM classe WHERE classe.id IN (SELECT c_id FROM req_raca WHERE r_id = (SELECT raca.id FROM raca WHERE nome = 'Humano'));

--SELECT * FROM habilidade WHERE habilidade.id IN (SELECT h_id FROM hab_gerais)
--	OR habilidade.id IN (SELECT h_id FROM rac_habilidades WHERE r_id = (SELECT raca.id FROM raca WHERE nome = 'Humano'))
--	OR habilidade.id IN (SELECT h_id FROM cla_habilidades WHERE c_id = (SELECT classe.id FROM classe WHERE nome = 'Bardo'));

--SELECT "public".equipamentos."id" FROM "public".equipamentos
--WHERE EXISTS (SELECT m_equip.e_id FROM m_equip WHERE m_equip.p_id = 1)
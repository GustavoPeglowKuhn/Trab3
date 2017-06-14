INSERT INTO public.classe(nome, atributos) VALUES ('Bardo',      '{0,1,0,1}');
INSERT INTO public.classe(nome, atributos) VALUES ('Druida',     '{0,0,1,1}');
INSERT INTO public.classe(nome, atributos) VALUES ('Espadachim', '{1,1,0,0}');

INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Anão')   );

INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT raca.id FROM raca WHERE raca.nome = 'Elfo')   );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Elfo')   );

INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Bardo'),      (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Druida'),     (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );
INSERT INTO rac_classes (c_id, r_id) VALUES ( (SELECT classe.id FROM classe WHERE classe.nome = 'Espadachim'), (SELECT raca.id FROM raca WHERE raca.nome = 'Humano') );

SELECT distinct(habilidade.id), nome FROM habilidade, hab_gerais, rac_habilidades, cla_habilidades WHERE
	(
		habilidade.id = hab_gerais.h_id OR
        (rac_habilidades.r_id = (SELECT raca FROM personagem WHERE personagem.id = 1)
            AND habilidade.id = rac_habilidades.h_id) OR
        (cla_habilidades.c_id = (SELECT classe FROM personagem WHERE personagem.id = 1)
            AND habilidade.id = cla_habilidades.h_id)
    ) AND (habilidade.id NOT IN (SELECT h_id FROM m_hab WHERE p_id = 1))

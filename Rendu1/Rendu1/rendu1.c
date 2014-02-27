
// Assign the number of group members to the symbol "NB_GROUP_MEMBERS"
#define RENDU1_NB_GROUP_MEMBERS 2

// Assign the sciper ids of your group members to the array below
// i.e Replace the 11 and 12 by your sciper ids
static int rendu1_sciper_ids[RENDU1_NB_GROUP_MEMBERS] = {234712, 236091};

float rendu1_rayon_intersecte (float dx, float dy, float ux, float uy, 
							   float cx, float cy, float r)
{
	
	return 9.0;
}

///// DO NOT TOUCH THE PART BELOW! /////
int rendu1_get_nb_students(void)
{
	return RENDU1_NB_GROUP_MEMBERS;
}

void rendu1_get_sciper_ids(int student_sciper_ids[])
{
	int i = 0;
	for(; i < RENDU1_NB_GROUP_MEMBERS; ++i)
		student_sciper_ids[i] = rendu1_sciper_ids[i];
}
///// DO NOT TOUCH THE PART ABOVE /////

#include <stdio.h>
#include <string.h>

int main(){
    
    
    char titre[100][100];
    char auteur[100][100];
    int prix[100];
    int quantity[100];
    int choix;
    int nblivres = 0;
    char recherche[100];
    int found, i;
    
    while(1) {
    
    printf("***********MENU***************\n");
    printf("1.  Ajouter un livre au stock : \n");
    printf("2.  Afficher tous les livres disponibles : \n");
    printf("3.  Rechercher un livre par son titre : \n");
    printf("4.  Mettre à jour la quantité d'un livre : \n");
    printf("5.  Supprimer un livre du stock : \n");
    printf("6.  Afficher le nombre total de livres en stock : \n");
    printf("0.  quitter\n");
    printf("option  :");
    scanf("%d",&choix);
    
    if(choix ==1){
        printf("veuillez saisir le titre du livre :");
        scanf(" %[^\n]", titre[nblivres]);
        printf("veuillez saisir l'auteur du livre :");
        scanf( " %[^\n]", auteur[nblivres]);
        printf("veuillez saisir le prix du livre :");
        scanf(" %d",&prix[nblivres]);
        printf("veuillez saisir la quantite en stock :");
        scanf(" %d",&quantity[nblivres]);
        nblivres++;
        printf("votre livre est ajoute avec succes\n");
    }
    else if(choix ==2){
        if (nblivres == 0){
            printf("Aucun livre dans le stock. \n");
        }
        else {
       for(i=0;i<nblivres;i++){
           printf("\nlivre %d:\n", i+1);
           printf("titre du livre est : %s\n",titre[i]);
           printf("auteur du livre est : %s\n",auteur[i]);
           printf("prix du livre est : %d\n",prix[i]);
           printf("quantite en stock est : %d\n",quantity[i]);
           printf("*************************************************\n");
       }
   }
}
else if (choix ==3){
    found = 0;
    printf("le titre du livre : ");
    scanf(" %[^\n]",recherche);
    for(i=0;i<nblivres;i++){
        if(strcmp(titre[i],recherche)==0){
            printf("titre du livre est : %s\n",titre[i]);
           printf("auteur du livre est : %s\n",auteur[i]);
           printf("prix du livre est : %d\n",prix[i]);
           printf("quantite en stock est : %d\n",quantity[i]);
           found =1;
           break;
        }
    }
    if(found != 1){
        printf("ce livre n est pas trouvé");
  
}

else if (choix ==4){

    printf("veuillez saisir le titre du livre a mettre a jour :");
    scanf(" %[^\n]", recherche);
    found=0;
    for(i = 0;i<nblivres;i++){
        if (strcmp(titre[i], recherche) ==0){
            printf("Quantité actuelle : %d\n", quantity[i]);
            printf("Veuillez saisir la nouvelle quantité : ");
            scanf("%d", &quantity[i]);
            printf("Quantité mise à jour.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
                printf("Livre non trouvé.\n");
                
    }
    
}
else if (choix == 5) {
            printf("Veuillez saisir le titre du livre à supprimer : ");
            scanf(" %[^\n]",recherche);
            
         found = 0;
            for (i = 0; i < nblivres; i++) {
                if (strcmp(titre[i], recherche) == 0) {
                    for (int j = i; j < nblivres - 1; j++) {
                        strcpy(titre[j], titre[j + 1]);
                        strcpy(auteur[j], auteur[j + 1]);
                        prix[j] = prix[j + 1];
                        quantity[j] = quantity[j + 1];
                    }
         nblivres--;
                    printf("Livre supprimé.\n");
                    found = 1;
                    break; 
                }
            }
            if (!found) {
                printf("Livre non trouvé.\n");
            }
}

else if (choix ==6){
  int totalequantity = 0;  
  printf("Nombre total de livres en stock : %d\n", nblivres);
  for(i=0;i<nblivres;i++){
      totalequantity = totalequantity + quantity[i];
  }
  printf("quantite totale de la librarie : %d\n", totalequantity);
    
}
else if (choix ==0){
    printf("Merci d'avoir utilisee notre bibliotheque\n");
}
else {
    printf("option invalid veuillez ressayer . \n");
}
    }

}
return 0;
}

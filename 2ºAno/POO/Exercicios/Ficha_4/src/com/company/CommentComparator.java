package com.company;

import java.util.Comparator;

public class CommentComparator implements Comparator<FBPost> {

    public int compare (FBPost a,FBPost b){
        if (a.getComentarios().size()>b.getComentarios().size()){
            return 1;
        }else{
            return 0;
        }
    }
}


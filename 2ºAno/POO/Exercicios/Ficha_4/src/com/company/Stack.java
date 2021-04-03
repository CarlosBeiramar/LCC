package com.company;

import java.util.ArrayList;

public class Stack {
    private ArrayList<String> stack = new ArrayList<String>();
    private int stackPointer;

    public Stack(){
        stack = new ArrayList<String>();
        stackPointer = 0;

    }

    public Stack(String s){
        stack.add(s);
        stackPointer++;
    }

    public Stack (Stack e){
        stack.clear();
        for(String s: e.getStack()){
            stack.add(s);
        }
        stackPointer = 0;
    }

    public String top(){
        return stack.get(stack.size()-1);
    }

    public void pop(){
        stack.remove(stack.size()-1);
        stackPointer--;
    }

    public void push(String s){
        stack.add(s);
        stackPointer++;
    }

    public boolean empty(){
        return (stack.size()==0);
    }

    public int length(){
        return stack.size();
    }

    /*
    getters
     */

    /*
copia os elementos da stack para um arraylist novo
 */
    public ArrayList<String> getStack(){
        ArrayList<String> res = new ArrayList<String>();
        for (String s:stack){
            res.add(s);
        }
        return res;
    }

    public int getStackPointer() {
        return this.stackPointer;
    }
}

using System;
using System.Collections;
using System.Collections.Generic;
using System.Data.SqlTypes;
using UnityEngine;

public class catFish : MovingCharacter
{
    public PlayerHealth Health;
    public int amountOfDamage;
    public Sounds Sounds;

    private void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Blue_Seaweed")
        {
            print("Blue");
            Sounds.playHitSeaweedClip();
            Health.Damage(amountOfDamage);
            Destroy(col.gameObject);
        }
        else if (col.gameObject.tag == "Trash")
        {
            print("green");
            Sounds.playHitTrashCLip();
            Health.Damage(amountOfDamage);
            Destroy(col.gameObject);
        }
        
    }

    public void DisableGameplay()
    {
        gameObject.SetActive(false);
    }

   
}


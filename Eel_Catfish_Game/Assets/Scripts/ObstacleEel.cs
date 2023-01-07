using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleEel : MonoBehaviour
{
    public PlayerHealth Health;
    public int amountOfDamage;

    private void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Green_Seaweed")
        {
            Health.Damage(amountOfDamage);
            Destroy(col.gameObject);
        }
        
    }
}

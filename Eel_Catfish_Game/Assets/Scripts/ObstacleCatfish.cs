using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleCatfish : MonoBehaviour
{
    public PlayerHealth Health;
    public int amountOfDamage;

    private void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Blue_Seaweed")
        {
            Health.Damage(amountOfDamage);
            Destroy(col.gameObject);
        }
        
    }
}

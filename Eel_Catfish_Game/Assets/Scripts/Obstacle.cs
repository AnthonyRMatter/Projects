using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obstacle : MonoBehaviour
{
    public PlayerHealth Health;
    public int amountOfDamage;

    private void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Trash")
        {
            Health.Damage(amountOfDamage);
            Destroy(col.gameObject);
        }
        
    }
}

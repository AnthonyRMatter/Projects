using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHealth : MonoBehaviour
{
    public float curHealth;

    public float maxHealth = 100;

    public UI UI;

    public Image healthBar;
    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ResetHealth()
    {
        
    }

    public void Damage(int damageValue)
    {
        healthBar.rectTransform.sizeDelta = new Vector2(healthBar.rectTransform.rect.width - damageValue, 5);
        if (healthBar.rectTransform.rect.width <= 0)
        {
            print("dead");
            isDead();
        }
    }

    public void isDead()
    {
        UI.ShowEndScreen();
    }
}

import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class ClienteService {

  constructor() { }

  public exibeAlerta() {
    alert('funciona');
  }
}

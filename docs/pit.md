# Chapter 1: PIT Library

## Functions

### PIT_SetReloadValue
```c
void PIT_SetReloadValue(u8_t channel, u16_t val);
```
**channel** - # of channel.  
**val** - New reload value

Sets the reload value of the selected channel.

### PIT_GetCurrentCount
### PIT_LatchCount
### PIT_SendCommand0